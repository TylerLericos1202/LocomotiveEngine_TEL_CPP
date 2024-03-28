/**
 * 3D Locomotive Engine
 * @Tyler Lericos
 * March 27th 2024
 * Demo 1
*/

#include <iostream>
#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "Player.hpp"
#include "Input.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


// Window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Cube position
float cubeX = 0.0f;
float cubeY = 0.0f;

// Camera position
float cameraX = 5.0f;
float cameraY = 5.0f;
float cameraZ = 5.0f;

// Time-related variables
Uint32 lastTime = 0;
const float movementSpeed = 2.0f; // Adjust as needed

// Function to set up OpenGL
void initGL() {
    // Set up perspective projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 1.0, 100.0);

    // Set up modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



// Function to draw a grid
void drawGrid() {
    glLineWidth(1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    for (float i = -10.0f; i <= 10.0f; i += 1.0f) {
        glVertex3f(i, -10.0f, 0.0f);
        glVertex3f(i, 10.0f, 0.0f);
        glVertex3f(-10.0f, i, 0.0f);
        glVertex3f(10.0f, i, 0.0f);
    }
    glEnd();
}

// Function to load the model using Assimp
bool loadModel(const std::string& filePath) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_FlipUVs);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "Failed to load model: " << importer.GetErrorString() << std::endl;
        return false;
    }
    
    // Process the loaded model...
    
    return true;
}


int main(int argc, char* argv[]) {
    // Initialize SDL and OpenGL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("OpenGL Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Enable depth testing for 3D rendering
    glEnable(GL_DEPTH_TEST);

    // Set up OpenGL
    initGL();
    Player player;
    Input input;

    // Main loop
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        // Calculate delta time
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f; // Convert to seconds
        lastTime = currentTime;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        //input.handleInput(player, deltaTime, cameraX, cameraY, cameraZ);
        input.cameraFlat(player, deltaTime);
        // Clear the screen and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Reset transformations
        glLoadIdentity();

        // Set the camera
        gluLookAt(cameraX+player.x, cameraY+player.y, cameraZ, player.x, player.y, 0.0f, 0.0f, 0.0f, 1.0f);

        // Draw the grid
        drawGrid();

        // Draw the cube
        player.drawCube();

        // Swap buffers
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

