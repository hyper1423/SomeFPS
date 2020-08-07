#version 450

layout (location = 0) in vec3 vertexPos;

out vec4 vertexColor;

void main() {
    gl_Position = vec4(vertexPos.x, -vertexPos.y, vertexPos.z, 1.0);
    vertexColor = vec4(1.0, 1.0, 0.0, 1.0);
}