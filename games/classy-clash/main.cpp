#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"

int main()
{
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;
    InitWindow(windowDimensions[0], windowDimensions[1], "Huw's Top Down");

    Texture2D map = LoadTexture("nature_tileset/world-map.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knight{windowDimensions[0], windowDimensions[1]};
   
    Prop props[] {
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png") },
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png") }
    };

    Enemy goblin{
        Vector2{},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};
        goblin.setTarget(&knight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        for (auto prop : props){
        prop.Render(knight.getWorldPos());
        };

        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + windowDimensions[0] > map.width * mapScale ||
            knight.getWorldPos().y + windowDimensions[1] > map.height * mapScale)
        {
            knight.undoMovement();
        };
        
        goblin.tick(GetFrameTime());

        //check prop collision
        for (auto prop: props)
        {
            if (
            CheckCollisionRecs(prop.getColRec(knight.getWorldPos()), knight.getColRec()))
            {
            knight.undoMovement();
            }
        }

        for (auto prop: props)
        {
            if (
            CheckCollisionRecs(prop.getColRec(goblin.getWorldPos()), goblin.getColRec()))
            {
            goblin.undoMovement();
            }
        }

        EndDrawing();
    }
    CloseWindow();
}