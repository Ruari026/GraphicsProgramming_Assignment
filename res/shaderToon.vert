#version 400

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexTexCoord;
layout (location = 2) in vec3 VertexNormal;

varying vec2 texCoord;
varying vec3 normal;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

void main()
{
	vec4 position = projection * transform * vec4(VertexPosition, 1.0);
	gl_Position = position;

	texCoord = VertexTexCoord;
	normal = VertexNormal;
}