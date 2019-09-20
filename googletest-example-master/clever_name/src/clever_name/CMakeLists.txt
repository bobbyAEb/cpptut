add_library(randomization randomization.cpp)


add_library(writer writer.cpp)
target_link_libraries(writer randomization)
