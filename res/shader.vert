#version 120

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec3 position0;
varying vec2 texCoord0;
varying vec3 normal0;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(position, 1.0);

	position0 = position;
	texCoord0 = texCoord;
	normal0 = normalize(normal);
}