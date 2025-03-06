#!/bin/bash

set -e  # Остановить выполнение при ошибке

echo "Обновление пакетов..."
sudo apt update

echo "Установка необходимых библиотек..."
sudo apt install -y \
    build-essential \
    cmake \
    libcurl4-openssl-dev \
    nlohmann-json3-dev \
    git

echo "Установка библиотек завершена!"

git clone https://github.com/japo0nn/ozya.git
