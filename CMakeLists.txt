cmake_minimum_required(VERSION 3.14)
project("Project1")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
enable_testing()

# Source files for the main program
set(SOURCE_FILES
    src/cpp/Data.cpp
    src/cpp/AddUrl.cpp
    src/cpp/App.cpp
    src/cpp/FindUrl.cpp
    src/cpp/FirstMenu.cpp
    src/cpp/MenuConsole.cpp
)

set(SOURCE_FILES_TEST
    src/cpp/Data.cpp
    src/cpp/AddUrl.cpp
    src/cpp/App.cpp
    src/cpp/FindUrl.cpp
    src/cpp/FirstMenu.cpp
    src/cpp/MenuConsole.cpp
)

# Header files for the main program
set(HEADER_FILES
    src/header/Data.h
    src/header/AddUrl.h
    src/header/App.h
    src/header/FindUrl.h
    src/header/FirstMenu.h
    src/header/MenuConsole.h
)

# Source files for the tests
set(TEST_FILES
    tests/test_main.cpp
    tests/calc_test.cpp
    # ${SOURCE_FILES}  # Include the source files for tests
)
set(MAIN_FILE
    src/cpp/Main.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Add main executable
add_executable(MainExecutable ${SOURCE_FILES} src/cpp/Main.cpp)

# Add test executable
#add_executable(CalcTests ${TEST_FILES} ${SOURCE_FILES_TEST})
add_executable(CalcTests ${TEST_FILES})

# Link Google Test to the test executable
target_link_libraries(CalcTests PRIVATE gtest gtest_main)

# Include the source directory for headers
# target_include_directories(MainExecutable PRIVATE src)
# target_include_directories(CalcTests PRIVATE src)

include(GoogleTest)
add_test(NAME CalcTests COMMAND CalcTests)
#add_test(NAME MainExecutable COMMAND MainExecutable)
