#include <nlohmann/json.hpp>

#include "http_request.h"
#include "iostream"
#include "result.h"

auto main() -> int {
    std::string url = "https://jsonplaceholder.org/posts";
    std::string body = "{\"title\":\"foo\",\"body\":\"bar\",\"userId\":1}";
    Result<nlohmann::json> res = send_http_request(url, MethodType::POST, body);

    std::cout << "main.cpp" << '\n';

    if (!res.isSuccess()) {
        std::cout << res.getError() << "\n";
    }
    return 0;
}
