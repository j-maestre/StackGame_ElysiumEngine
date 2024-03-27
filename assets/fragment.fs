#version 330

uniform vec4 u_color;

in vec3 normals;
out vec4 fragColor;

void main()
{
   fragColor = vec4(normals,1.0);
}
