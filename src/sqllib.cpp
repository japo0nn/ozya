#include "sqllib.h"

#include <cstdio>

#include "headers.h"

auto sql_init(const char *filename) -> sqlite3 * {
    sqlite3 *database = nullptr;
    char *err_msg = 0;
    int result = sqlite3_open(filename, &database);
    if (result == SQLITE_OK) {
        std::cout << "Connection established: " << result << "\n";
    } else {
        // выводим сообщение об ошибке
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(database));
        sqlite3_close(database);
    }
    char *sql =
        "CREATE TABLE IF NOT EXISTS messages(id INTEGER PRIMARY KEY AUTOINCREMENT, message TEXT, "
        "role TEXT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);";

    result = sqlite3_exec(database, sql, 0, 0, &err_msg);
    if (result != SQLITE_OK) {
        std::cout << "SQL error: " << err_msg;
        sqlite3_free(err_msg);  // очищаем ресурсы
        sqlite3_close(database);
        return database;
    }
    sqlite3_close(database);
    std::cout << "Table created\n";
    return database;
}
