cmake_minimum_required(VERSION 3.0)
project(MySQLiteProject)

find_package(SQLiteCpp CONFIG REQUIRED)  # Поиск установленной библиотеки SQLiteCPP

# Исходные файлы вашего проекта
set(SOURCES src/main.cpp)

# Генерация исполняемого файла
add_executable(MySQLiteProject ${SOURCES})

# Привязка библиотеки SQLiteCPP
target_link_libraries(MySQLiteProject PRIVATE SQLiteCpp)
