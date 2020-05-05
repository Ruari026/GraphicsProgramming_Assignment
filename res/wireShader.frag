//Version number
#version 400

in vec3 dist;

varying vec2 texCoord;
varying vec3 normal;

uniform sampler2D diffuse;
uniform mat4 transform;

//Layout Qualifer
layout( location = 0 ) out vec4 fragcolor;

void main()
{
    vec4 wireColor = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 fillColor = vec4(0.0, 0.0, 0.0, 0.0);

    // Compute the shortest distance to the edge
    float d = min(dist[0], min(dist[1], dist[2]));

    // Compute line intensity and then fragment color
    float I = exp2(-2.0*d*d);

    // Calculating Final Color
    // if dist.z == 1 then use the fillColor, if dist.z == 0 then use the wirecolor
    vec4 color = I * wireColor + (1.0 - I) * fillColor;

    gl_FragColor = color;
}