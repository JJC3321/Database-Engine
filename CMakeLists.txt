cmake_minimum_required(VERSION 3.10)
project(ComposerDatabase VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create a library for the database engine
add_library(database_lib 
    database.cpp
    information.cpp
)

# Make headers available to the library and anything that links to it
target_include_directories(database_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Test executables
add_executable(testDatabase test/testDatabase.cpp)
target_link_libraries(testDatabase PRIVATE database_lib)

add_executable(testInformation test/testInformation.cpp)
target_link_libraries(testInformation PRIVATE database_lib)

# Enable testing with CTest
enable_testing()
add_test(NAME DatabaseTest COMMAND testDatabase)
add_test(NAME InformationTest COMMAND testInformation)

# Set the working directory for tests so they can access the data folder
set_tests_properties(DatabaseTest PROPERTIES 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
set_tests_properties(InformationTest PROPERTIES 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Print some useful information
message(STATUS "")
message(STATUS "Composer Database Configuration:")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  Source Directory: ${CMAKE_SOURCE_DIR}")
message(STATUS "  Binary Directory: ${CMAKE_BINARY_DIR}")
message(STATUS "")

