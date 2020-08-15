
cmake_minimum_required (VERSION 3.0)

SET(CMAKE_BUILD_TYPE "Release")

# set the C++ standard to C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project (ECSProfile)

find_package(glm CONFIG REQUIRED)

add_executable(ECSProfile src/main.cpp)

# libs
target_link_libraries(ECSProfile PRIVATE glm)