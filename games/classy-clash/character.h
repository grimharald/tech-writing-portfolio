#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include "baseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Vector2 getWorldPos() { return worldPos; }

private:
    int windowWidth{};
    int windowHeight{};
};

#endif