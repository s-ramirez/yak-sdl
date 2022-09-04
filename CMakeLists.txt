cmake_minimum_required(VERSION 3.10)

project(yak)

# C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(yak
    src/game.cpp
    src/entity.cpp
    src/internal/renderer.cpp
    src/components/graphics/sprite.cpp
)

target_include_directories(yak
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(yak ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})