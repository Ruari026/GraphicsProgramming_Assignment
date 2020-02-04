#version 400
in vec4 v_pos; 
in vec2 v_texCoord;
in vec3 v_norm;

uniform mat4 transform;
uniform mat4 projection;

// Object Details
uniform sampler2D diffuse;

// Fog Details
uniform vec4 fogColor;
uniform float maxDist; //fog max distance
uniform float minDist; //fog min distance

// Camera Details
uniform vec3 cam_pos;

void main() 
{
	float dist = distance(v_pos.xyz, cam_pos);
	dist = v_pos.z;

	float fogFactor = (maxDist - dist)/(maxDist - minDist);
	fogFactor = clamp(fogFactor, 0.0, 1.0);

	vec4 color = texture2D(diffuse, v_texCoord);
	color = mix(fogColor, color, fogFactor);

	gl_FragColor = vec4(color.xyz, 1.0);
}