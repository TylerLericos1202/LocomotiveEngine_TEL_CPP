// Cube.cpp
#include <OpenGL/gl.h>
#include "Cube.hpp"

Cube::Cube() {}

// Function to draw a cube
void Cube::drawCube() {
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f + cubeX, -0.5f + cubeY, 0.5f);  // Bottom-left
    glVertex3f(0.5f + cubeX, -0.5f + cubeY, 0.5f);   // Bottom-right
    glVertex3f(0.5f + cubeX, 0.5f + cubeY, 0.5f);    // Top-right
    glVertex3f(-0.5f + cubeX, 0.5f + cubeY, 0.5f);   // Top-left
    glEnd();
}

