// Input.hpp
#ifndef INPUT_HPP
#define INPUT_HPP

class Player; // Forward declaration

class Input {
public:
    void cameraFlat(Player &player, float deltaTime);

    void handleInput(Player &player, float deltaTime, float cameraX, float cameraY, float cameraZ);
};

#endif
