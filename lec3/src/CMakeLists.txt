add_library(hello hello.cpp)
add_library(blar blar.cpp)
add_executable(bin_main test.cpp)
target_link_libraries(bin_main hello)