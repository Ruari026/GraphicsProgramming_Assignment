#version 400

uniform vec3 lightDir = vec3(0, 0, 0);

varying vec2 texCoord;
varying vec3 normal;

uniform sampler2D diffuse;

void main()
{
	vec4 color = texture2D(diffuse, texCoord);

	float intensity;
	intensity = dot(lightDir, normal);

	if (intensity > 0.75)
		color *= 1.0;
	else if (intensity > 0.5)
		color *= 0.5;
	else if (intensity > 0.25)
		color *= 0.25;
	else
		color *= 0.0;

	gl_FragColor = vec4(color.xyz, 1.0);
}