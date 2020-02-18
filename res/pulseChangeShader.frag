#version 400

uniform vec3 pulsePoint;
uniform float pulseSize;

varying vec3 position;
varying vec2 texCoord;
varying vec3 normal;

uniform sampler2D diffuse;
uniform mat4 transform;

void main()
{
	vec4 color = texture2D(diffuse, texCoord);

	gl_FragColor = vec4(color.xyz, 1.0);
}