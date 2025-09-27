cmake_minimum_required(VERSION 3.10)
project(myProgram1.7)

set(CMAKE_C_STANDARD 11)  # Используем стандарт C11
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=maybe-uninitialized")

set(LIB_SOURCES
 src/file_processing.c
 src/opt_processing.c
)

add_library(${PROJECT_NAME}_lib STATIC ${LIB_SOURCES})


# Директории с заголовками
target_include_directories(${PROJECT_NAME}_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib m)
