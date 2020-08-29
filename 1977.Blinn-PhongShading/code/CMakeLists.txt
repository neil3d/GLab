cmake_minimum_required(VERSION 3.1.0)

project(GLab)

set(SUB_PROJECT_NAME BlinnPhongShading)

# target
add_executable(${SUB_PROJECT_NAME} main.cpp
	)

# libs
target_link_libraries(${SUB_PROJECT_NAME} GKit)
