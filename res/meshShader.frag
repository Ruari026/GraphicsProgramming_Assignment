//Version number
#version 430

//Layout Qualifer
layout( location = 0 ) out vec4 fragcolor;
 
in vec2 v_coord;

uniform sampler2D diffuse;

void main()
{
	//Setting each vector component to uniform varaible then setting final colour
	vec4 color = texture2D(diffuse, v_coord);

    fragcolor = color;
}