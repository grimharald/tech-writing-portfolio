#include "raylib.h"
#include "raymath.h"
#include "baseCharacter.h"

class Enemy : public BaseCharacter
{
    public:
        Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
        Vector2 getWorldPos() { return worldPos; }
        void setScreenPos(int winWidth, int winHeight);
        void tick(float deltaTime);
        void undoMovement();
        Rectangle getColRec();

    private:
        Texture2D texture{LoadTexture("characters/goblin_idle_spritesheet.png")};
        Texture2D idle{LoadTexture("characters/goblin_idle_spritesheet.png")};
        Texture2D run{LoadTexture("characters/goblin_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 worldPosLastFrame{};
        // 1 = facing right -1 = facing left
        float rightLeft{1.f};

        // anim variables
        float runningTime{};
        int frame{};
        int maxFrames{6};
        float updateTime{1.f / 12.f};
        float speed{4.f};

        float width{};
        float height{};
        float scale{4.0f};
};