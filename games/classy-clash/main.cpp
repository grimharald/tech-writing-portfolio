#include "raylib.h"
#include "raymath.h"

int main()
{
    // window array
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;

    //window
    InitWindow(windowDimensions[0],windowDimensions[1],"Huw top down");


    //load background 
    Texture2D background = LoadTexture("nature_tileset/world-map.png");
    Vector2 mapPos{0.0,0.0};

    SetTargetFPS(60); 

    //set speed
    float speed{4.0};

    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)windowDimensions[0] / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
        (float)windowDimensions[1] / 2.0f - 4.0f * (0.5f * (float)knight.height)

    };

    //1 = facing right -1 = facing left
    float rightLeft{1.f};

    //anim variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    const float updateTime{1.f/12.f};


    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        // draw background
        DrawTextureEx(background, mapPos, 0.0, 4.0, WHITE);
        

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;

        if (Vector2Length(direction) !=0.0){

            // set mapPos = mapPos - direction
            Vector2Normalize(direction);
            mapPos = Vector2Subtract(mapPos,  Vector2Scale(Vector2Normalize(direction), speed));
            direction.x <0.f ? rightLeft = -1.f: rightLeft = 1.f;
            knight = knight_run;

        }
        else
        {
            knight = knight_idle;
        };

        //anim frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime) {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
        };

        // draw character
        Rectangle source{frame * ((float)knight.width / 6.f), 0.f, rightLeft * (float)knight.width / 6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width / 6.0f, 4.0f * knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    CloseWindow();
}
