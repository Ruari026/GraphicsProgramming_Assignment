//Version Number
#version 430

//The layout qualifers
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexCoord;
layout (location = 2) in vec3 VertexNormal;

//Uniform variable
uniform mat4 transform;
uniform mat4 projection;

//Passing out the normal and position data
out vec4 v_pos;
out vec2 v_coord;
out vec3 v_norm;

void main()
{
	//Assigning the normal and position data
	v_norm = VertexNormal;
	v_coord = VertexCoord;
	v_pos = vec4(VertexPosition, 1.0);

	// Sets the position of the current vertex
	gl_Position =  vec4(VertexPosition, 1.0);
}