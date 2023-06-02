#include "raylib.h"
#include "raymath.h"
#include "character.h"


int main()
{
    // window array
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;

    // window
    InitWindow(windowDimensions[0], windowDimensions[1], "Huw top down");

    // load background
    Texture2D background = LoadTexture("nature_tileset/world-map.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knight;
    knight.setScreenPos(windowDimensions[0],windowDimensions[1]);


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        // draw background
        DrawTextureEx(background, mapPos, 0.0, mapScale, WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        knight.tick(GetFrameTime());
        //check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + windowDimensions[0] > background.width * mapScale||
            knight.getWorldPos().y + windowDimensions[1] > background.height * mapScale) 
        {
            knight.undoMovement();
        };

        EndDrawing();
    }
    CloseWindow();
}
