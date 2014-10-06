#version 330 core

in vec3 Position;
in vec4 Color;
in vec2 Texcoord;

layout(location = 0)out vec4 color;

uniform vec3 camera_pos;
uniform vec3 model_position;
uniform sampler2D tex;

void main(){
   vec3 block_color = vec3(0.3, 0.6 , 0.2);
   float colorMultiplier = 1.0 / length(camera_pos - model_position);
   vec3 bc = block_color * model_position / 30.0f;
   bc *= colorMultiplier * 20.0f - 0.2f;
   color = texture(tex, Texcoord) * vec4(bc, 1.0f);
}