cmake_minimum_required(VERSION 3.25)
project(dataconverter)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

#add_executable(dataconverter
#        src/data_converter.h
#        src/data_converter.cpp
#        src/source.cpp
#        src/source.h
#        src/sink.cpp
#        src/sink.h
#        tst/data_converter_test.cpp)
