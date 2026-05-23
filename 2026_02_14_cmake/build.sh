#!/bin/bash

: '
Вид сборки / суффикс в названии каталога сборки

"Ninja" / "ninja"
"Visual Studio 17 2022" / "visual_studio" (недоступен в Linux)
'

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

# Установка локали для поддержки UTF-8
export LANG=ru_RU.UTF-8
export LC_ALL=ru_RU.UTF-8

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="projects"

# Создание папки сборки, если она не существует
if [ ! -d "$BUILD_FOLDER" ]; then
    mkdir "$BUILD_FOLDER"
fi

# Переход в папку сборки
cd "$BUILD_FOLDER" || exit 1

# Генерация файлов сборки
cmake -G "$BUILD_TYPE" "../${SOURCE_FOLDER}"

# Выполнение сборки
cmake --build .

# Возврат в исходную директорию
cd ..
