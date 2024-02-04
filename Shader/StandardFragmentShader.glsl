#version 330 core

layout(location = 0) out vec4 color;
layout(location = 0) in vec3 pos;

void main(){
    color = vec4(pos.x + 0.5f,pos.y + 0.5f,pos.z + 0.5f,1.0f);
}