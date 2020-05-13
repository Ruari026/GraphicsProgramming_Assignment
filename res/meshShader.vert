//Version Number
#version 430

//The layout qualifers
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexCoord;
layout (location = 2) in vec3 VertexNormal;

//Passing out the texture coordinate information
out vec2 v_coord;

void main()
{
	//Assigning the normal and position data
	v_coord = VertexCoord;

	// Sets the position of the current vertex
	gl_Position =  vec4(VertexPosition, 1.0);
}