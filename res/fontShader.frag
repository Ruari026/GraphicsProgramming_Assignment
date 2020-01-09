#version 330

varying vec3 position0;
varying vec2 texCoord0;
varying vec3 normal0;

uniform mat4 transform;
uniform mat4 projection;
uniform sampler2D diffuse;

void main()
{
	vec2 textureCoordinate = vec2(texCoord0.x, texCoord0.y);
	vec4 objectColour = texture2D(diffuse, textureCoordinate);

	// Setting new colour
	gl_FragColor = vec4(objectColour.xyz, 1.0);
}