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
out vec3 v_norm;
out vec3 v_pos; 

void main()
{
	//Assigning the normal and position data
	v_norm =  (transform * vec4(VertexNormal, 0.0)).xyz;
	v_pos =  (transform * vec4(VertexPosition, 1.0)).xyz;

	// Sets the position of the current vertex
	gl_Position = projection * transform * vec4(VertexPosition, 1.0);
}