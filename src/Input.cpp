// Input.cpp
#include "Input.hpp"
#include "Player.hpp" // Include the full definition of Player
#include <SDL2/SDL.h>
#include <iostream>

void Input::cameraFlat(Player& player, float deltaTime) {
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (keyboardState[SDL_SCANCODE_LEFT]) {
        player.x -= player.movementSpeed * deltaTime;
    }
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
        player.x += player.movementSpeed * deltaTime;
    }
    if (keyboardState[SDL_SCANCODE_UP]) {
        player.y += player.movementSpeed * deltaTime;
    }
    if (keyboardState[SDL_SCANCODE_DOWN]) {
        player.y -= player.movementSpeed * deltaTime;
    }

    
}


void Input::handleInput(Player& player, float deltaTime, float cameraX, float cameraY, float cameraZ) {
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (keyboardState[SDL_SCANCODE_LEFT]) {
        player.x -= player.movementSpeed * deltaTime;
    }
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
        player.x += player.movementSpeed * deltaTime;
    }
    if (keyboardState[SDL_SCANCODE_UP]) {
        player.y += player.movementSpeed * deltaTime;
    }
    if (keyboardState[SDL_SCANCODE_DOWN]) {
        player.y -= player.movementSpeed * deltaTime;
    }

    // Update camera position to follow the player
    cameraX = player.x + 5.0f;
    cameraY = 5.0f;
    cameraZ = 5.0f; // Adjust as needed
    
    // Print camera information
    std::cout << "Camera Position: (" << cameraX << ", " << cameraY << ", " << cameraZ << ")" << std::endl;
}

