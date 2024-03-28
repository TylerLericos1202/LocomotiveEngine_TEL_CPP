cmake_minimum_required(VERSION 3.12)
project(Engine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Set OpenGL on macOS
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# Find Assimp
find_package(assimp REQUIRED)
include_directories(${ASSIMP_INCLUDE_DIRS})

# Source files
file(GLOB SOURCES "src/*.cpp")

# Include directories
include_directories(
    include
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${ASSIMP_LIBRARIES})
