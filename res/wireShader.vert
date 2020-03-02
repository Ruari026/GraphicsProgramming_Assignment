//Version Number
#version 400

//The layout qualifers
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexCoord;
layout (location = 2) in vec3 VertexNormal;

//Uniform variable
uniform mat4 transform;
uniform mat4 projection;

//Passing out the normal and position data
out vec3 normal;
out VS_OUT 
{
    vec2 texCoords;
} vs_out;
out vec4 position; 


void main()
{
	//Assigning the normal and position data
	normal = VertexNormal;
	vs_out.texCoords = VertexCoord;
	position = vec4(VertexPosition, 1.0);

	// Sets the position of the current vertex
	gl_Position = projection * transform * vec4(VertexPosition, 1.0);
}