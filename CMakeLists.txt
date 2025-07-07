cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED False)

project(NationSim)
include_directories(NationSim src/Classes/headers)
add_executable(EcoSimulator src/main.cpp src/Classes/nation.cpp)