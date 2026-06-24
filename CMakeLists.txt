cmake_minimum_required(VERSION 4.0)
project(CashFlowTracker VERSION 0.1.0 LANGUAGES C CXX)

# set C and C++ standards
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF )

# subdirectories
add_subdirectory(core)                # core library
add_subdirectory(apps/cli)            # command-line interface target
add_subdirectory(third-party/sqlite)  # third-party SQLite library

# global compiler flags
add_compile_options(-g)

# strict warnings only for local code
target_compile_options(tracker_core PRIVATE -Wall -Wextra -Wpedantic -Werror)           # core library compiler flags
target_compile_options(cli-cashflow-tracker PRIVATE -Wall -Wextra -Wpedantic -Werror)   # command-line interface compiler flags

# third-party libraries
target_link_libraries(tracker_core PUBLIC sqlite_lib)

# additional compiler flags for optimization and architecture-specific features
if (UNIX AND NOT ANDROID)
  target_link_libraries(tracker_core PRIVATE pthread dl)
endif()

# build type 
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Debug build")
  target_compile_definitions(tracker_core PRIVATE DEBUG_BUILD=1)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
  message(STATUS "Release build")
  target_compile_definitions(tracker_core PRIVATE RELEASE_BUILD=1)
endif()

# target_compile_options(${PROJECT_NAME} PRIVATE -march=x86-64-v2)
# target_compile_options(${PROJECT_NAME} PRIVATE -march=native)