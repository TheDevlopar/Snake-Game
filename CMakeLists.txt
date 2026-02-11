cmake_minimum_required(VERSION 3.20)

project(SnakeRaylib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib installed on the system
find_package(raylib REQUIRED)

# Tell compiler where headers live
include_directories(include)

# Grab all .cpp files
file(GLOB SRC_FILES src/*.cpp)

# Create executable
add_executable(Snake ${SRC_FILES})

# Link raylib to our game
target_link_libraries(Snake raylib)
