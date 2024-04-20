# Set minimum CMake Version
cmake_minimum_required(VERSION 3.29)

# Constants
set(BUILD_FOR_WINDOWS OFF CACHE BOOL "Force build Windows version on linux")

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
file(GLOB SOURCES "src/*.cpp" "src/**/*.cpp")


# MinGW (Windows)
if(BUILD_FOR_WINDOWS)
  set(CMAKE_SYSTEM_NAME Windows)
  set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
  set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
  set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)
  set(CMAKE_MAKE_PROGRAM x86_64-w64-mingw32-make)
endif()

# Finding Library Paths
find_path(RAYLIB_INCLUDE_DIR NAMES raylib.h HINTS "${CMAKE_SOURCE_DIR}/include")

# Finding Libraries
if(WIN32 OR BUILD_FOR_WINDOWS)
  find_library(RAYLIB_LIBRARY NAMES raylib.win HINTS "${CMAKE_SOURCE_DIR}/lib")
else()
  find_library(RAYLIB_LIBRARY NAMES raylib PATHS ${CMAKE_SOURCE_DIR}/lib)
endif()

# Make an executable with SOURCES
add_executable(${PROJECT_NAME} ${SOURCES})

# Define the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)

# Define the destination directory (build directory)
set(DEST_DIR ${CMAKE_CURRENT_BINARY_DIR}/res)

# DLL Files
if(BUILD_FOR_WINDOWS)
  file(GLOB dll_files ${CMAKE_SOURCE_DIR}/lib/*.dll)
  foreach(dll_file ${dll_files})
    file(COPY ${dll_file} DESTINATION ${CMAKE_SOURCE_DIR}/build)
  endforeach()
endif()

# Linking Libraries
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src ${RAYLIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${RAYLIB_LIBRARY})
