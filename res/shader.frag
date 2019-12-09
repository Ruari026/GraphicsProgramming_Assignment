#version 120

varying vec3 position0;
varying vec2 texCoord0;
varying vec3 normal0;

uniform sampler2D diffuse;

void main()
{
	// Getting colour from texture
	vec4 objectColour = texture2D(diffuse, texCoord0);


	// Light Details
	vec3 lightPos = vec3(0.0, 5.0, 0.0);
	vec3 lightColour = vec3(1.0, 1.0, 1.0);


	// Basic Lighting - Ambient
	float ambientStrength = 0.25;
	vec3 ambient = ambientStrength * lightColour;


	// Basic Lighting - Diffuse
	vec3 lightDirection = normalize(lightPos - position0);
	float diff = max(dot(normal0, lightDirection), 0.0);
	vec3 diffuse = diff * lightColour;


	// Setting new colour
	vec3 colour = vec3(objectColour.x, objectColour.y, objectColour.z);
	vec3 lighting = (ambient + diffuse);
	vec3 result = lighting * colour;
	gl_FragColor = vec4(result, 1.0);
}