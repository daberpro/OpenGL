cmake_minimum_required(VERSION 3.27.2)
project(Main VERSION 1.0.0)

add_executable(${PROJECT_NAME} Main.cpp)
message("Check Dependencies")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS --static)
set(CMAKE_CXX_FLAGS -static-libstdc++)
set(all_dependencies glfw3 GLEW)

foreach(package IN LISTS all_dependencies)
    find_package(${package} REQUIRED PATHS /Dependencies)  
    if(${package}_FOUND)
        message("FOUND ${package} VERSION ${${package}_VERSION}")
    endif()
endforeach()

find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    message("FOUND OpenGL VERSION ${${OpenGL}_VERSION}")
endif()

target_link_directories(${PROJECT_NAME} PUBLIC ${OpenGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} glfw GLEW::GLEW ${OPENGL_LIBRARY})
