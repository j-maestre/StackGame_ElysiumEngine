#version 330
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

in vec3 FragPos;
in vec2 Uv;
in vec3 Normal;

uniform sampler2D u_texture;
uniform uint u_entity;

void main(){
  gPosition = FragPos;
  gNormal = Normal;
  gAlbedoSpec.rgb = texture(u_texture, Uv).rgb;
  gAlbedoSpec.a = u_entity;
}
