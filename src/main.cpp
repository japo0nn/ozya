#include <iostream>

#include "config.h"
#include "gptlib.h"
#include "headers.h"

auto main() -> int {
    try {
        nlohmann::json config = config_init();
        std::cout << config["apiKey"].get<std::string>() << '\n';
        GPT gpt =
            GPT::Create(config["mode"].get<std::string>(), config["apiKey"].get<std::string>());

        std::cout << gpt.GetMode() << "\n";
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}
