cmake_minimum_required(VERSION 3.20)
project(Test)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-15")

execute_process(
    COMMAND xcrun --show-sdk-path
    OUTPUT_VARIABLE APPLE_SDK_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread --sysroot=${APPLE_SDK_PATH}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --sysroot=${APPLE_SDK_PATH}")

add_executable(main
    main.cpp
    Board.cpp
    calculations.cpp
    experiment.cpp
)
