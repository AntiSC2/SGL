#version 330 core

layout(location = 0)in vec3 position;
layout(location = 2)in vec2 texcoord;

out vec4 Color;
out vec2 Texcoord;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;

void main(){
   gl_Position = projection * view * model * vec4(position.xy, position.z /*+ sin(time)*/, 1.0);
   Color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
   Texcoord = texcoord;
}