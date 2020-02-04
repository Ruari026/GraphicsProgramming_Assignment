#version 400

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexTexCoord;
layout (location = 2) in vec3 VertexNormal;

uniform mat4 transform;
uniform mat4 projection;

out vec4 v_pos;
out vec2 v_texCoord;
out vec3 v_norm;

void main()
{
	v_pos = transform * vec4(VertexPosition, 1.0);
	v_texCoord = VertexTexCoord;
	v_norm = VertexNormal;


	gl_Position = projection * v_pos;
}