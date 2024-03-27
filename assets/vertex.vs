#version 330
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormals;
layout (location = 2) in vec2 aUv;

out vec3 normals;
out vec2 uv;
out vec3 object_pos;
out vec4 object_pos_light_space[6];

uniform mat4 u_model;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_light_space[6];

void main()
{
  object_pos = vec3(u_model * vec4(aPos, 1.0));
  gl_Position = u_projection * u_view * u_model * vec4(aPos, 1.0f);
  normals = normalize(mat3(transpose(inverse(u_model))) * aNormals);;
  uv = aUv;
  for(int i = 0; i < 6; ++i){
    object_pos_light_space[i] = u_light_space[i] * vec4(object_pos, 1.0);
  }
}
