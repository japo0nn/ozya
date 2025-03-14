#include <cstring>

#include "curl/curl.h"
#include "headers.h"

using std::string;

static auto WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) -> size_t {
    ((string*) userp)->append((char*) contents, size * nmemb);
    return size * nmemb;
}

auto method_to_string(MethodType method) -> string {
    switch (method) {
        case MethodType::POST:
            return "POST";
        case MethodType::PUT:
            return "PUT";
        case MethodType::PATCH:
            return "PATCH";
        case MethodType::DELETE:
            return "DELETE";
        case MethodType::GET:
            return "GET";
        default:
            return "UNKNOWN";
    }
};

auto send_http_request(const string& url, MethodType method, const nlohmann::json& body,
                       const string& token) -> Result<nlohmann::json> {
    CURL* curl = curl_easy_init();
    if (!curl) return Result<nlohmann::json>::Failure("Curl initialization error!");
    std::string response_json;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_json);

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    std::string json_str = "";
    if (!body.empty()) json_str = body.dump();

    std::cout << json_str << '\n';

    switch (method) {
        case MethodType::POST:
        case MethodType::PUT:
        case MethodType::PATCH:
        case MethodType::DELETE:
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method_to_string(method).c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
            break;
        default:
            break;
    }

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    if (token != "") {
        std::string auth_header = "Authorization: Bearer " + token;
        headers = curl_slist_append(headers, auth_header.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode res = curl_easy_perform(curl);
    std::cout << res << "\n";
    if (res != CURLE_OK) {
        std::cerr << "Ошибка запроса: " << curl_easy_strerror(res) << std::endl;
        return Result<nlohmann::json>::Failure(
            string("Request error: ").append(curl_easy_strerror(res)));
    }
    if (response_json == "") response_json = "{}";
    nlohmann::json response = nlohmann::json::parse(response_json);
    return Result<nlohmann::json>::Success(response);
}
