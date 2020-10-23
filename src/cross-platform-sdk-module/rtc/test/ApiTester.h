#ifndef ApiTester_h
#define ApiTester_h

#include "LogJson.h"

#define AGORO_ENABLE_TEST

namespace agora {
namespace common {

class APICaseHandler {
public:
  virtual void handleAPICase(int apiType, const char *paramter) = 0;
  virtual ~APICaseHandler() {}
};

LogJson &GetApiJsonLogger();

void BeginApiTest(const char *caseFilePath, APICaseHandler *apiCaseHandler);

void CompareAndDumpApiTestResult(const char *caseFilePath,
                                 const char *dumpFilePath,
                                 APICaseHandler *apiCaseHandler);

#ifdef AGORO_ENABLE_TEST

#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, \
                  _15, NAME, ...)                                              \
  NAME
#define LOG_JSON(...)                                                          \
  GET_MACRO(__VA_ARGS__, LOG_JSON15, LOG_JSON14, LOG_JSON13, LOG_JSON12,       \
            LOG_JSON11, LOG_JSON10, LOG_JSON9, LOG_JSON8, LOG_JSON7,           \
            LOG_JSON6, LOG_JSON5, LOG_JSON4, LOG_JSON3, LOG_JSON2, LOG_JSON1)  \
  (__VA_ARGS__)

#define LOG_JSON1(t1) agora::common::GetApiJsonLogger().log(t1)
#define LOG_JSON2(t1, t2) agora::common::GetApiJsonLogger().log(t1, t2)
#define LOG_JSON3(t1, t2, t3) agora::common::GetApiJsonLogger().log(t1, t2, t3)
#define LOG_JSON4(t1, t2, t3, t4)                                              \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4)
#define LOG_JSON5(t1, t2, t3, t4, t5)                                          \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5)
#define LOG_JSON6(t1, t2, t3, t4, t5, t6)                                      \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6)
#define LOG_JSON7(t1, t2, t3, t4, t5, t6, t7)                                  \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7)
#define LOG_JSON8(t1, t2, t3, t4, t5, t6, t7, t8)                              \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8)
#define LOG_JSON9(t1, t2, t3, t4, t5, t6, t7, t8, t9)                          \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8, t9)
#define LOG_JSON10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10)                    \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10)
#define LOG_JSON11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11)               \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8, t9,    \
                                        t10, t11)
#define LOG_JSON12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12)          \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8, t9,    \
                                        t10, t11, t12)
#define LOG_JSON13(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13)     \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8, t9,    \
                                        t10, t11, t12, t13)
#define LOG_JSON14(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13,     \
                   t14)                                                        \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8, t9,    \
                                        t10, t11, t12, t13, t14)
#define LOG_JSON15(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13,     \
                   t14, t15)                                                   \
  agora::common::GetApiJsonLogger().log(t1, t2, t3, t4, t5, t6, t7, t8, t9,    \
                                        t10, t11, t12, t13, t14, t15)
#else

#define LOG_JSON(...)

#endif

} // namespace common
} // namespace agora

#endif /* ApiTester_h */
