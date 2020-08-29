cmake_minimum_required(VERSION 3.1.0)
project(GLab)

set(SUB_PROJECT_NAME GKit)

# dependencies
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

# add sub folder source files
aux_source_directory(./framework FRAMEWORK_SRC)

add_library(${SUB_PROJECT_NAME} STATIC 
                ${FRAMEWORK_SRC}
            )

target_include_directories(${SUB_PROJECT_NAME}
            PUBLIC ${PROJECT_SOURCE_DIR}
        )            

# libs
target_link_libraries(${SUB_PROJECT_NAME} PUBLIC 
                        glm glfw
                        imgui::imgui
                        )