// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
    Player();
    const float movementSpeed = 2.0f; // Adjust as needed
    void update(float deltaTime);
    float x;
    float y;
    void drawCube();
    
    
private:
    float velocityX;
    float velocityY;
    
    float vx;
    float vy;
};

#endif
