#include "headers.h"

auto str_replace_all(std::string str, const std::string from, const std::string to) -> std::string {
    if (from.empty()) return str;
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
    return str;
}
