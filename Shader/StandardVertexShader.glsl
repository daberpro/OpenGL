#version 330 core

layout(location = 0) in vec4 position;
layout(location = 0) out vec3 pos;

void main(){
    gl_Position = position;
    pos = gl_Position.xyz;
}