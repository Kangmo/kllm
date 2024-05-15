cmake_minimum_required(VERSION 3.2)
project(kml C CXX)

set(SOURCE_FILES
    kml.h
    kml.cpp
)

add_library(kml SHARED STATIC ${SOURCE_FILES})

install(TARGETS kml DESTINATION ${KLLM_INSTALL_LIB_DIR})
install(FILES kml.h DESTINATION ${KLLM_INSTALL_INCLUDE_DIR})
