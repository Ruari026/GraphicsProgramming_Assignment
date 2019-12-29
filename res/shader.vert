#version 330

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec3 position0;
varying vec2 texCoord0;
varying vec3 normal0;

uniform mat4 transform;
uniform mat4 projection;

void main()
{
	vec4 vertexPosition = projection * transform * vec4(position, 1.0);
	gl_Position = vertexPosition;

	position0 = vec3(transform * vec4(position, 1.0));
	texCoord0 = texCoord;
	normal0 = mat3(transpose(inverse(transform))) * normal;
}