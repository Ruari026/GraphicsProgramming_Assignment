#version 430

out vec4 FragColor;

in vec3 v_norm;
in vec3 v_pos;

uniform vec3 cameraPos;
uniform samplerCube skybox;

void main()
{             
    vec3 I = normalize(v_pos - cameraPos);
    vec3 R = reflect(I, normalize(v_norm));

    FragColor = vec4(texture(skybox, R).rgb, 1.0);
}