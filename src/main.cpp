#include <iostream>

#include "config.h"
#include "gptlib.h"
#include "headers.h"
#include "sqllib.h"

auto main() -> int {
    try {
        /* nlohmann::json config = config_init(); */
        /* GPT gpt = gpt_init(config["mode"].get<std::string>(), config["model"].get<std::string>(),
         */
        /*                    config["apiKey"].get<std::string>()); */
        /* std::string message = ""; */
        /* std::cout << "Ваше сообщение: "; */
        /* std::getline(std::cin, message); */
        /*  */
        /* std::string response = gpt_send_message(gpt, message); */
        /* std::cout << "\nАссистент: " << response << '\n'; */
        const char* filename = "test.db";
        sqlite3* database = sql_init(filename);
        sqlite3_close(database);
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}
