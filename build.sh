#!/bin/bash

set -e  # Останавливаем выполнение при ошибке

# Создание директории сборки
BUILD_DIR="build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cp ./resources/* ./build

# Переход в директорию сборки
cd "$BUILD_DIR"

# Запуск CMake и сборка проекта
cmake ..
make -j$(nproc)

# Запуск исполняемого файла (если необходимо)
./ozya

