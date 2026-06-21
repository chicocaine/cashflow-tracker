add_library(tracker_core
  src/account.c
)

target_include_directories(tracker_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)