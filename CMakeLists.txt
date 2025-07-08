cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED False)

project(NationSim)
include(CTest)
add_executable(ProvinceUnitTests src/Classes/provinceTests.cpp)
add_executable(NationTests src/Classes/NationTests.cpp)
add_test(NAME ProvinceTests COMMAND ProvinceUnitTests)
add_test(NAME NationTests COMMAND NationTests)
include_directories(NationSim src/Classes/headers)
add_executable(EcoSimulator src/main.cpp src/Classes/nation.cpp src/Classes/province.cpp)