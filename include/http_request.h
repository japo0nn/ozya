#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include "result.h"
#include "string"

Result send_http_request(std::string url, std::string body);

#endif
