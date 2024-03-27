#version 330
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aUv;

out vec2 Uv;

void main()
{
  Uv = aUv;
  gl_Position = vec4(aPos, 1.0);
}
