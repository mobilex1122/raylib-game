# Set minimum CMake Version
cmake_minimum_required(VERSION 3.29)

# Set Project name
project(game VERSION 1.0)

# Check If RayLib exists 
find_package(raylib 3.0 REQUIRED)

# Set CPP Standart
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Copy Resources to Build
file(REMOVE res)
file(COPY res DESTINATION .)


# Search for all .cpp files and save them to SOURCES
file(GLOB SOURCES "src/*.cpp")

# Make an executable with SOURCES
add_executable(${PROJECT_NAME} ${SOURCES})

# Define the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)

# Define the destination directory (build directory)
set(DEST_DIR ${CMAKE_CURRENT_BINARY_DIR}/res)

# Link RayLib
target_link_libraries(${PROJECT_NAME} raylib)