cmake_minimum_required(VERSION 3.2)
project(kllm)

add_subdirectory(kml)
set(SOURCE_FILES main.cpp)

add_executable(kllm ${SOURCE_FILES})
target_link_libraries(kllm kml)
install(TARGETS kllm DESTINATION ${KLLM_INSTALL_BIN_DIR})
