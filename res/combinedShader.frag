#version 400

varying vec3 position;
varying vec2 texCoord;
varying vec3 normal;

uniform sampler2D diffuse;
uniform mat4 transform;

// Toon Details
uniform vec3 lightDir;

// Fog Details
uniform vec4 fogColor;
uniform float maxDist; //fog max distance
uniform float minDist; //fog min distance

// Rim Details
uniform vec3 cameraPos;
uniform float rimSize;

void main()
{
	vec4 color = texture2D(diffuse, texCoord);

	// Toon Shader
	float intensity = dot(lightDir, normal);
	if (intensity > 0.75)
		color *= 1.0;
	else if (intensity > 0.5)
		color *= 0.5;
	else if (intensity > 0.25)
		color *= 0.25;
	else
		color *= 0.0;


	// Fog Shader
	float dist = distance((transform * vec4(position.xyz, 1.0)).xyz, cameraPos);

	float fogFactor = (maxDist - dist)/(maxDist - minDist);
	fogFactor = clamp(fogFactor, 0.0, 1.0);

	color = mix(fogColor, color, fogFactor);


	// Rim Shader
	vec3 viewDirection = position.xyz - cameraPos;
	viewDirection = normalize(viewDirection);

	vec3 norm = normalize(normal);

	float angle = dot(norm, viewDirection);
	if ((angle > -rimSize) && (angle < rimSize))
	{
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}


	gl_FragColor = vec4(color.xyz, 1.0);
}