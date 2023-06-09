#include "enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex)
{
    worldPos = pos;
    texture = idle_tex;
    idle = idle_tex;
    run = run_tex;

    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
};

void Enemy::tick(float deltaTime){
    //Get ToTarget
    velocity = Vector2Subtract(target->getScreenPos(),getScreenPos()); 
    BaseCharacter::tick(deltaTime);
};

Vector2 Enemy::getScreenPos(){
    return Vector2Subtract(worldPos, target->getWorldPos());
};
