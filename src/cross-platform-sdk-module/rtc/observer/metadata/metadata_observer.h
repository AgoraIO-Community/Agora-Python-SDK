#pragma once

#include "../../common/IBridgeCommon.h"
#include "../../include/IAgoraRtcEngine.h"
#include <functional>
#include <mutex>
#include <queue>
#include <string>

namespace agora {
namespace common {
class MetadataObserver : public rtc::IMetadataObserver {

public:
  MetadataObserver(rtc::IMetadataObserver *_observer);

  virtual ~MetadataObserver();

  virtual int getMaxMetadataSize() override;

  virtual bool
  onReadyToSendMetadata(rtc::IMetadataObserver::Metadata &metadata) override;

  virtual void
  onMetadataReceived(const rtc::IMetadataObserver::Metadata &metadata) override;

  int sendMetadata(Metadata *metadata);

  int setMaxMetadataSize(int size);

  void clearData();

private:
  std::queue<rtc::IMetadataObserver::Metadata *> messageQueue;
  std::mutex queueMutex;
  rtc::IMetadataObserver *_metadataObserver = nullptr;
  int MAX_METADATA_SIXE = 1024;
  const int QUEUE_MAX_CACHE_LENGTH = 50;
};
} // namespace common
} // namespace agora