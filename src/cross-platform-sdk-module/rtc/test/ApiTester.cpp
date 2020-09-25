#include "ApiTester.h"
#include "LogJson.h"
#include <fstream>
#include <thread>

#include "../common/rapidjson/istreamwrapper.h"
#include "../common/rapidjson/ostreamwrapper.h"
#include "../common/rapidjson/stringbuffer.h"
#include "../common/rapidjson/writer.h"

using namespace std;

namespace agora {
namespace common {

using rapidjson::Document;
using rapidjson::Value;

LogJson &GetApiJsonLogger() {
  static LogJson logJson;
  return logJson;
}

void BeginApiTest(const char *caseFilePath, APICaseHandler *apiCaseHandler) {
  ifstream ifs(caseFilePath);
  rapidjson::IStreamWrapper isw(ifs);

  Document caseDoc;
  caseDoc.ParseStream(isw);

  GetApiJsonLogger().clearJsonData();

  for (auto &v : caseDoc.GetArray()) {
    int apiType = v["apitype"].GetInt();
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    v["param"].Accept(writer);
    const char *param = buffer.GetString();
    apiCaseHandler->handleAPICase(apiType, param);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
  apiCaseHandler->handleAPICase(-1, "{}");
}

void CompareAndDumpApiTestResult(const char *caseFilePath,
                                 const char *dumpFilePath,
                                 APICaseHandler *apiCaseHandler) {
  GetApiJsonLogger().compareAndDumpResult(caseFilePath, dumpFilePath);
}

} // namespace common
} // namespace agora
