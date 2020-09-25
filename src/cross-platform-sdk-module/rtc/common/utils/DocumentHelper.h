//
// Created by 张涛 on 2020-08-10.
//

#pragma once

#include <string>

#include "../../common/IBridgeCommon.h"
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"

namespace agora {
namespace common {
template <typename T>
void get_parameter_int(T &doc, const char *key, int &value, int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsInt()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetInt();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_uint(T &doc, const char *key, unsigned int &value,
                        int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsUint()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetUint();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_bool(T &doc, const char *key, bool &value, int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsBool()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetBool();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_int64(T &doc, const char *key, long long &value, int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsInt64()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetInt64();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_float(T &doc, const char *key, float &value, int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsNumber()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetFloat();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_double(T &doc, const char *key, double &value, int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsNumber()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetDouble();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_string(T &doc, const char *key, std::string &value,
                          int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsString()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetString();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_object(T &doc, const char *key, rapidjson::Value &value,
                          int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsObject()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetObject();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}

template <typename T>
void get_parameter_array(T &doc, const char *key, rapidjson::Value &value,
                         int &ret) {
  if (doc.HasMember(key)) {
    rapidjson::Value &val = doc[key];
    if (!val.IsArray()) {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
    value = val.GetArray();
  } else {
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
  }
}
} // namespace common
} // namespace agora
