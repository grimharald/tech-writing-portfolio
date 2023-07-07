#include "raylib.h"
#include "raymath.h"
#include "baseCharacter.h"
#include "character.h"

class Enemy : public BaseCharacter
{
    public:
        Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
        virtual void tick(float deltaTime) override;
        void setTarget(Character* character) {target = character;}
        
    private:
        Character* target;
        };