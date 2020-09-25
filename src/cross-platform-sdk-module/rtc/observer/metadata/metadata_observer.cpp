#include "metadata_observer.h"

namespace agora {
namespace common {
using namespace rtc;

MetadataObserver::MetadataObserver(rtc::IMetadataObserver *_observer)
    : _metadataObserver(_observer) {}

MetadataObserver::~MetadataObserver() { clearData(); }

void MetadataObserver::clearData() {
  std::lock_guard<std::mutex> lock(queueMutex);
  while (!messageQueue.empty()) {
    Metadata *metadata = messageQueue.front();
    if (metadata) {
      if (metadata->buffer) {
        free(metadata->buffer);
        metadata->buffer = nullptr;
      }
      delete metadata;
      metadata = nullptr;
    }
    messageQueue.pop();
  }
  _metadataObserver = nullptr;
}

int MetadataObserver::getMaxMetadataSize() { return MAX_METADATA_SIXE; }

bool MetadataObserver::onReadyToSendMetadata(Metadata &metadata) {
  std::lock_guard<std::mutex> lock(queueMutex);
  if (!messageQueue.empty()) {
    Metadata *cachedMetadata = messageQueue.front();
    if (cachedMetadata) {
      metadata.uid = cachedMetadata->uid;
      metadata.size = cachedMetadata->size;
      metadata.timeStampMs = cachedMetadata->timeStampMs;
      if (cachedMetadata->buffer) {
        memcpy(metadata.buffer, cachedMetadata->buffer, metadata.size);
        cachedMetadata->buffer[cachedMetadata->size] = '\0';
        metadata.buffer[metadata.size] = '\0';
        if (_metadataObserver) {
          _metadataObserver->onReadyToSendMetadata(*cachedMetadata);
        }
        free(cachedMetadata->buffer);
        cachedMetadata->buffer = nullptr;
      }
      delete cachedMetadata;
      cachedMetadata = nullptr;
    }
    messageQueue.pop();
    return true;
  }
  return false;
}

void MetadataObserver::onMetadataReceived(const Metadata &metadata) {
  std::lock_guard<std::mutex> lock(queueMutex);
  _metadataObserver->onMetadataReceived(metadata);
}

int MetadataObserver::sendMetadata(Metadata *_metadata) {
  std::lock_guard<std::mutex> lock(queueMutex);
  if (messageQueue.size() > QUEUE_MAX_CACHE_LENGTH) {
    Metadata *metadata = messageQueue.front();
    if (metadata) {
      if (metadata->buffer) {
        free(metadata->buffer);
        metadata->buffer = nullptr;
      }
      delete metadata;
      metadata = nullptr;
    }
    messageQueue.pop();
  }
  Metadata *metadata = new Metadata();
  metadata->uid = _metadata->uid;
  metadata->size = _metadata->size;
  unsigned int memorySize = (_metadata->size + 1);
  void *cachePtr = malloc(memorySize);
  if (cachePtr) {
    metadata->buffer = static_cast<unsigned char *>(std::move(cachePtr));
    memset(cachePtr, 0, memorySize);
    memcpy(metadata->buffer, _metadata->buffer, _metadata->size);
    metadata->timeStampMs = _metadata->timeStampMs;
    messageQueue.push(metadata);
  }
  return ERROR_CODE::ERROR_OK;
}

int MetadataObserver::setMaxMetadataSize(int size) {
  MAX_METADATA_SIXE = size;
  return ERROR_CODE::ERROR_OK;
}
} // namespace common
} // namespace agora