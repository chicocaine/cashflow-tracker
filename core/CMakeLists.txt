add_library(tracker_core
  src/account.c
  src/transaction.c
)

target_include_directories(tracker_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)