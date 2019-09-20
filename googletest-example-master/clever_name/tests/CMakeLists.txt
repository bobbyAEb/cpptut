## If you are on Ubuntu, install gtest sources with:
##
##     sudo apt install libgtest-dev
##
## If you are not on Ubuntu, you will need to download the source of the
## googletest framework manually and provide the folder to which you have
## - downloaded it by copying this link into your browser:
##   https://github.com/google/googletest/archive/release-1.8.0.zip
## - unpack it into some <FOLDER>
## - use this <FOLDER> instead of /usr/src/gtest in the line below.
add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
# Set binary name for convenience.
set(TEST_BINARY ${PROJECT_NAME}_test)
# This is an executable that runs the tests.
add_executable(${TEST_BINARY}
               test_random.cpp
               test_writer.cpp)
# Link the executable to needed libraries.
target_link_libraries(${TEST_BINARY}
  randomization
  writer
  gtest gtest_main  # GTest libraries
)
# Add gtest to be able to run ctest
add_test(
  NAME ${TEST_BINARY}
  COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})
