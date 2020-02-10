#version 400

uniform vec3 cameraPos;
uniform float rimSize;

varying vec4 position;
varying vec2 texCoord;
varying vec3 normal;

uniform sampler2D diffuse;
uniform mat4 transform;

void main()
{
	vec4 color = texture2D(diffuse, texCoord);

	vec3 direction = cameraPos - position.xyz;

	float angle = dot(direction, normal);

	// Front of object
	if (angle > (1.0 - rimSize) && angle < (1.0 + rimSize))
	{
		color = vec4(1.0, 1.0, 1.0, 1.0);
	}

	gl_FragColor = vec4(color.xyz, 1.0);
}