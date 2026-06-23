cmake_minimum_required(VERSION 4.0)

project(sqlite_lib C)

add_library(sqlite_lib STATIC sqlite3.c)

target_include_directories(sqlite_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Recommended production flags for SQLite
target_compile_definitions(sqlite_lib PRIVATE 
  SQLITE_ENABLE_FTS5              # Enables Full-Text Search
  SQLITE_ENABLE_RTREE             # Enables Geo-spatial indexing
  SQLITE_THREADSAFE=1             # Ensures thread safety
)