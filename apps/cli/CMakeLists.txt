add_executable(cli-cashflow-tracker src/main.cpp)

target_link_libraries(cli-cashflow-tracker PRIVATE tracker_core)

target_compile_options(cli-cashflow-tracker PRIVATE -O2)