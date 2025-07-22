cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(NationSim)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


include_directories(NationSim src/Classes/headers)
add_executable(NationSim src/main.cpp src/Classes/nation.cpp src/Classes/province.cpp)

enable_testing()

add_executable(ProvinceTests src/Classes/provinceTests.cpp)
target_link_libraries(ProvinceTests GTest::gtest_main)
add_executable(NationTests src/Classes/nationTests.cpp)
target_link_libraries(NationTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ProvinceTests)
gtest_discover_tests(NationTests)
