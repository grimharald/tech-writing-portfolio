#include "raylib.h"
#include "raymath.h"
#include "baseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    void tick(float deltaTime);


private:

};
