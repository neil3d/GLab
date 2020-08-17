cmake_minimum_required(VERSION 3.1.0)

project(GLab)

set(SUB_PROJECT_NAME BlinnPhongShading)

# dependencies
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(tinyobjloader CONFIG REQUIRED)   

# target
add_executable(${SUB_PROJECT_NAME} main.cpp
                GLMesh.h
                GLProgram.h
                MyCamera.h
                MyFileLoader.h
                MyLight.h
                MyMaterial.h
                MyRenderer.h MyRenderer.cpp 
                MyScene.h MyScene.cpp
                MySceneObject.h
                )
# include
target_include_directories(${SUB_PROJECT_NAME}
            PUBLIC ${PROJECT_SOURCE_DIR}/glad/include
        )                         

# libs
target_link_libraries(${SUB_PROJECT_NAME} PRIVATE 
                        glfw OpenGL::GL
                        glm
                        tinyobjloader::tinyobjloader
                    )                