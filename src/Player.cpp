// Player.cpp
#include <OpenGL/gl.h>
#include "Player.hpp"

Player::Player() : velocityX(0.0f), velocityY(0.0f) {}



void Player::update(float deltaTime) {
    // Update player position based on input and elapsed time
}



// Function to draw a cube
void Player::drawCube() {
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f + x, -0.5f + y, 0.5f);  // Bottom-left
    glVertex3f(0.5f + x, -0.5f + y, 0.5f);   // Bottom-right
    glVertex3f(0.5f + x, 0.5f + y, 0.5f);    // Top-right
    glVertex3f(-0.5f + x, 0.5f + y, 0.5f);   // Top-left
    glEnd();
}