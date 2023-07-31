cmake_minimum_required(VERSION 3.12)

# Get the project directory name
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${PROJECT_NAME})
message("Project Name: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Remove main.cpp from SOURCE to allow test main function to run
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Generate the executable for the main function with main.cpp added back int
add_executable(${PROJECT_NAME} "src/main.cpp" ${SOURCES})

# Link any necessary libraries here, if needed

# Find Google Test package
find_package(GTest CONFIG REQUIRED)

# Include Google Test directories
include_directories(${GTEST_INCLUDE_DIRS})

# Add test source files
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Generate the test executable
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES} ${SOURCES})

# Link Google Test to the test executable
target_link_libraries(${PROJECT_NAME}_test GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)