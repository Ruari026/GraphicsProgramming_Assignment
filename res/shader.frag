#version 330

varying vec3 position0;
varying vec2 texCoord0;
varying vec3 normal0;

uniform mat4 transform;
uniform mat4 projection;
uniform sampler2D diffuse;

void main()
{
	// Lighting Details
	vec3 lightPos = vec3(1.0, 2.0, -1.0);
	vec3 lightColour = vec3(1.0, 1.0, 1.0);

	vec2 textureCoordinate = vec2(texCoord0.x, -texCoord0.y);
	vec4 objectColour = texture2D(diffuse, textureCoordinate);
	vec3 viewPos = vec3(0, 3, -4);


	// Basic Lighting - Ambient
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColour;

	// Basic Lighting - Diffuse
	float diffuseStrength = 0.2;
	vec3 lightDirection = normalize(lightPos - position0);
	float diff = max(dot(normal0, lightDirection), 0.0);
	vec3 diffuse = diffuseStrength * diff * lightColour;

	// Basic Lighting - Specular
	float specularStrength = 0.5;
	vec3 viewDirection = normalize(viewPos - position0);
	vec3 reflectDirection = reflect(-lightDirection, normal0);
	float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), 128);
	vec3 specular = specularStrength * spec * lightColour;

	// Setting new colour
	vec3 result = (ambient + diffuse + specular) * objectColour.xyz;
	gl_FragColor = vec4(objectColour.xyz, 1.0);
}