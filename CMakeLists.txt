cmake_minimum_required(VERSION 3.10)

project(ozya)

# Устанавливаем стандарт C
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем директорию с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/include)


find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# Автоматически находим все файлы .cpp в папке src
file(GLOB SRC_FILES src/*.cpp)

# Добавляем все найденные файлы в исполняемый файл
add_executable(ozya ${SRC_FILES})

target_link_libraries(ozya PRIVATE CURL::libcurl nlohmann_json::nlohmann_json)
