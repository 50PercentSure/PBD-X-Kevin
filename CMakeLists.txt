cmake_minimum_required(VERSION 3.10)
project(PBD-X LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    src/main.cpp
    src/core/PointMass.cpp
    src/core/Spring.cpp
    src/simulation/Simulation.cpp
    src/objects/ClothObject.cpp
    src/objects/RopeObject.cpp
)

include_directories(
    src/
    src/core/
    src/simulation/
    src/objects/
    src/utils/
)

add_executable(pbd-x ${SOURCES})