cmake_minimum_required(VERSION 3.7)
project(gyrus_arduino_uno)

set(CMAKE_CXX_STANDARD 11)
# Change as required
set(RIVULET_SRC ../../rivulet)

include_directories(
        ${RIVULET_SRC}/src
        src
        lib)

file(GLOB src src/*.c)
file(GLOB test test/*.c)

add_subdirectory("${RIVULET_SRC}" rivulet)

add_library(gyrus_arduino_uno STATIC ${src})
target_link_libraries(gyrus_arduino_uno rivulet)

add_executable(gyrus_arduino_uno_test ${test})
target_link_libraries(gyrus_arduino_uno_test LINK_PUBLIC rivulet gyrus_arduino_uno)