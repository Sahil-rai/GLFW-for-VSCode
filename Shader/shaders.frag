// shaders.frag
#version 460 core

in vec3 color;      // Color from Vertex Shader
in vec2 texCoord;   // Texture Coords from Vertex Shader

out vec4 FragColor;

uniform sampler2D uTexture; 

void main()
{
    // Временно выводим ТОЛЬКО цвет текстуры. 
    // Если после этого куб станет цветным, проблема в 'vec4(color, 1.0)'.
    FragColor = texture(uTexture, texCoord); 
    
    // Если хотите проверить, что фрагментный шейдер вообще работает:
    // FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Должен стать красным
}