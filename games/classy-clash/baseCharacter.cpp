#include "baseCharacter.h"


BaseCharacter::BaseCharacter()
{
    
}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
};

Rectangle BaseCharacter::getColRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale};
};