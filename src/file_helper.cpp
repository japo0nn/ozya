#include <sstream>
#include <stdexcept>

#include "headers.h"

auto get_file_content(const std::string& file_path) -> std::string {
    std::ifstream fin;
    fin.open(file_path);

    if (!fin.is_open()) {
        throw std::runtime_error("file open error");
    }

    std::stringstream buffer;
    buffer << fin.rdbuf();
    return buffer.str();
}
