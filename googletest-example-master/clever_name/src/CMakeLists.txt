add_subdirectory(clever_name)

# add executable main
add_executable(main tools_main.cpp)
# tell the linker to bin these objects together
target_link_libraries(main randomization)
