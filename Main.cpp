#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Headers/FileReader.h"
#include "Headers/Shader.h"

int main(){

    GLFWwindow* app;

    if(!glfwInit()){
        std::cout << "Failed to init glfw\n";
        exit(EXIT_FAILURE);
    }

    app = glfwCreateWindow(400,400,"OpenGL",nullptr,nullptr);
    glfwMakeContextCurrent(app);

    if(glewInit() != GLEW_OK){
        std::cout << "Failed to init glew\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    std::cout << "OpenGL Version " << glGetString(GL_VERSION) << "\n";

    GLuint shader = createShader(
        __current_path+"/../Shader/StandardVertexShader.glsl",
        __current_path+"/../Shader/StandardFragmentShader.glsl"
    );
    glUseProgram(shader);

    while(!glfwWindowShouldClose(app)){

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f,0.5f);
        glVertex2f(-0.5f,-0.5f);
        glVertex2f(0.5f,-0.5f);
        glEnd();

        glfwSwapBuffers(app);
        glfwPollEvents();

    }

    glfwTerminate();
    return EXIT_SUCCESS;
}