cmake_minimum_required(VERSION 3.2)
project(kllm_tests)

add_subdirectory(lib/googletest)

include_directories(${KML_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/kllm_tests.cpp)

add_executable(kllm_tests ${SOURCE_FILES})
target_link_libraries(kllm_tests kml gtest)
install(TARGETS kllm_tests DESTINATION bin)

