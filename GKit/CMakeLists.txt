cmake_minimum_required(VERSION 3.1.0)
project(GLab)

set(SUB_PROJECT_NAME MyFramework)

add_library(${SUB_PROJECT_NAME} STATIC 
            )

target_include_directories(${SUB_PROJECT_NAME}
            PUBLIC ${PROJECT_SOURCE_DIR}
        )            