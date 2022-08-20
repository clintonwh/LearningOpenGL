#version 330 core
out vec4 FragColor;

uniform vec3 ambientColor;
uniform vec3 diffusetColor;

void main()
{
    vec3 specular =  vec3 (0.5f);
    vec3 result = ambientColor + diffusetColor + specular;
    FragColor = vec4(result, 1.0);

}
