cmake_minimum_required(VERSION 4.0)
project(CashFlowTracker VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF )

add_compile_options(-g -Wall -Wextra -Wpedantic -Werror)

add_subdirectory(core)
add_subdirectory(apps/cli)

# target_compile_options(${PROJECT_NAME} PRIVATE)
# target_compile_options(${PROJECT_NAME} PRIVATE -march=x86-64-v2)
# target_compile_options(${PROJECT_NAME} PRIVATE -march=native)