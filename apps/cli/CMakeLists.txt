add_executable(cli_cashflow_tracker src/main.cpp)

target_link_libraries(cli_cashflow_tracker PRIVATE tracker_core)

target_compile_options(cli_cashflow_tracker PRIVATE -O2)