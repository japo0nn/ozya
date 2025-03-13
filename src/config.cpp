#include "config.h"

#include "headers.h"

auto config_init() -> nlohmann::json {
    std::string file_path = "./config.json";
    std::string content = get_file_content(file_path);

    if (content == "") content = "{}";
    nlohmann::json config = nlohmann::json::parse(content);
    return config;
}
