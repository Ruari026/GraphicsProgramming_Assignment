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

	vec3 viewDirection = position.xyz - cameraPos;
	viewDirection = normalize(viewDirection);

	vec3 norm = normalize(normal);

	float angle = dot(norm, viewDirection);
	//angle = (1.0 - angle);

	if ((angle > -rimSize) && (angle < rimSize))
	{
		color = vec4(1.0, 1.0, 1.0, 1.0);
	}
	else if (angle >= rimSize)
	{
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}
	else if (angle <= -rimSize)
	{
		color = vec4(0.0, 0.0, 1.0, 1.0);
	}

	gl_FragColor = vec4(color.xyz, 1.0);
}