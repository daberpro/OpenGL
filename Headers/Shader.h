#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "FileReader.h"

GLuint compileShader(const std::string& sourceCode,GLuint type){
    
    GLuint shaderId = glCreateShader(type);
    const char* src = sourceCode.c_str();
    glShaderSource(shaderId,1,&src,nullptr);
    glCompileShader(shaderId);

    int length;
    glGetShaderiv(shaderId,GL_INFO_LOG_LENGTH,&length);
    if(length > 0){
        char* message = (char*)alloca(length*sizeof(char));
        glGetShaderInfoLog(shaderId,length,nullptr,message);
        std::cout << "Shader Error ";
        std::cout << message << "\n"; 
    }

    return shaderId;
}

GLuint createShader(const std::string& vertexPath,const std::string& fragmentPath){

    std::string vertexSource,fragmentSource;
    readFile(vertexPath,vertexSource);
    readFile(fragmentPath,fragmentSource);

    GLuint vertexId = compileShader(vertexSource,GL_VERTEX_SHADER);
    GLuint fragmentId = compileShader(fragmentSource,GL_FRAGMENT_SHADER);

    GLuint program = glCreateProgram();
    glAttachShader(program,vertexId);
    glAttachShader(program,fragmentId);
    glLinkProgram(program);

    glDetachShader(program,vertexId);
    glDetachShader(program,fragmentId);
    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);

    int length;
    glGetProgramiv(program,GL_INFO_LOG_LENGTH,&length);
    if(length > 0){
        char* message = (char*)alloca(length*sizeof(char));
        glGetProgramInfoLog(program,length,nullptr,message);
        std::cout << "Program Error ";
        std::cout << message << "\n"; 
    }

    return program;

}

