#include <iostream>

#include "config.h"
#include "gptlib.h"
#include "headers.h"

auto main() -> int {
    try {
        nlohmann::json config = config_init();
        GPT gpt = gpt_init(config["mode"].get<std::string>(), config["model"].get<std::string>(),
                           config["apiKey"].get<std::string>());
        std::string message = "";
        std::cout << "Ваше сообщение: ";
        std::cin >> message;
        std::string response = gpt_send_message(gpt, "Hello!");
        std::cout << "\nАссистент: " << response << '\n';
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}
