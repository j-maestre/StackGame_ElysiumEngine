#version 330
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aUv;

out vec3 FragPos;
out vec2 Uv;
out vec3 Normal;

uniform mat4 u_model;
uniform mat4 u_projection;
uniform mat4 u_view;

void main()
{
  FragPos = vec3(u_model * vec4(aPos, 1.0));

  Uv = aUv;
  Normal = normalize(mat3(transpose(inverse(u_model))) * aNormal);

  gl_Position = u_projection * u_view * u_model * vec4(aPos, 1.0);
}
