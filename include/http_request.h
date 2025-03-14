#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <sys/types.h>

#include <nlohmann/json.hpp>

#include "result.h"
#include "string"

enum class MethodType { POST, GET, PUT, PATCH, DELETE };

auto send_http_request(const std::string& url, MethodType method, const nlohmann::json& body = {},
                       const std::string& token = "") -> Result<nlohmann::json>;

#endif
