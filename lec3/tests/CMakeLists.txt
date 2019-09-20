
add_subdirectory(/usr/src/gtest
                ${PROJECT_BINARY_DIR}/gtest)
include(CTest)      
add_executable(test_blar test_blar.cpp) 
target_link_libraries(test_blar gtest gtest_main blar)
add_test(test_blar tests/test_blar)     

