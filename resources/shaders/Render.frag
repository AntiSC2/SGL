#version 330 core

in vec4 Color;
in vec2 Texcoord;

layout(location = 0)out vec4 color;

uniform sampler2D tex;

void main(){
   color = texture(tex, Texcoord) * Color;
}