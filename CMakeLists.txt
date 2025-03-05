cmake_minimum_required(VERSION 3.10)

project(ozya)

# Устанавливаем стандарт C
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем директорию с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/include)


find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# Указываем исходные файлы
add_executable(ozya src/main.cpp src/http_request.cpp)
target_link_libraries(ozya PRIVATE CURL::libcurl nlohmann_json::nlohmann_json)
