cmake_minimum_required(VERSION 3.21...3.31)

project(Chip-8_Emulator VERSION 1.0
                        DESCRIPTION "Emulating Chip-8 for practice"
                        LANGUAGES C)

add_executable(Emulator src/main.c
                        src/chip8.c)

find_package(raylib REQUIRED)

target_link_libraries(Emulator raylib)
target_include_directories(Emulator PRIVATE include)
target_compile_features(Emulator PRIVATE c_std_23)
target_compile_options(Emulator PRIVATE -Wall -Wextra -Werror)
