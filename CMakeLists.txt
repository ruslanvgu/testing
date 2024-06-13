cmake_minimum_required(VERSION 3.8)
project(TestProject)

option(USE_STATIC "Use static library " ON)
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")

set(val 100)
message(${val})

include("external.cmake")

set(SOURCES 
    src/main.cpp
)

set(LIB_SOURCES 
    lib/libmessage.c 
)



if(USE_STATIC)
    add_library(libmessage STATIC ${LIB_SOURCES})
    set_target_properties(libmessage PROPERTIES LINKER_LANGUAGE C)
else()
    add_library(libmessage SHARED ${LIB_SOURCES})
    set_target_properties(libmessage PROPERTIES LINKER_LANGUAGE C)
endif()

add_executable(TestProject ${SOURCES})

find_library(LIBMESSAGE_LIBRARY libmessage
    HINTS ${CMAKE_SOURCE_DIR}/lib      # Путь к библиотеке
    PATH_SUFFIXES Debug                 # Подкаталог Debug (если применимо)
)

target_link_libraries(TestProject libmessage)

