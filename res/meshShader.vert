#version 430

//The layout qualifers
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexCoord;
layout (location = 2) in vec3 VertexNormal;

//Uniform variable
uniform mat4 transform;
uniform mat4 projection;

void main () 
{
	vec4 pos = projection * transform * vec4(VertexPosition, 1.0);

	gl_Position = vec4 (VertexPosition, 1.0);
}