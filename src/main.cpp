#include <iostream>

#include "headers.h"

auto main() -> int {
    try {
        std::string filePath = "./config.json";
        std::string content = get_file_content(filePath);
        nlohmann::json jsonString = nlohmann::json::parse(content);
        std::cout << jsonString["ApiKey"] << '\n';
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}
