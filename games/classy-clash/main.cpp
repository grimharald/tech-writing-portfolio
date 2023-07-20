#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"
#include <string>

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

    Prop props[]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}};

    Enemy goblin{
        Vector2{800.f, 300.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};

    Enemy slime{
        Vector2{500.f, 700.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")};

    Enemy *enemies[]{
        &goblin,
        &slime};

    for (auto enemy : enemies)
    {
        enemy->setTarget(&knight);
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        };

        // Health display
        if (!knight.getAlive()) // Character is dead
        {
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }
        else // Character is alive
        {
            std::string knightsHealth = "Health: ";
            knightsHealth.append(std::to_string(knight.getHealth()), 0, 5);

            DrawText(knightsHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + windowDimensions[0] > map.width * mapScale ||
            knight.getWorldPos().y + windowDimensions[1] > map.height * mapScale)
        {
            knight.undoMovement();
        };

        for (auto enemy : enemies)
        {
            enemy->tick(GetFrameTime());
        }

        // check prop collision
        for (auto prop : props)
        {
            if (
                CheckCollisionRecs(prop.getColRec(knight.getWorldPos()), knight.getColRec()))
            {
                knight.undoMovement();
            }
        }

        // draw props
        for (auto prop : props)
        {
            if (
                CheckCollisionRecs(prop.getColRec(goblin.getWorldPos()), goblin.getColRec()))
            {
                goblin.undoMovement();
            }
        };

        for (auto enemy : enemies)
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (CheckCollisionRecs(enemy->getColRec(), knight.getWeaponColRec()))
                {
                    enemy->setAlive(false);
                };
            };
        }
        EndDrawing();
    }
    CloseWindow();
}