#include "raylib.h"

int main()
{


    int width; width = 800;
    int height; height = 450;
    InitWindow(width,height,"Huw");
    
    //initial coordinates
    int circleRadius{25};
    int circleX{200};
    int circleY{200};
    //circle edges
    int lCircleX{circleX - circleRadius};
    int rCircleX{circleX + circleRadius};
    int uCircleY{circleY - circleRadius};
    int bCircleY{circleY + circleRadius};
    
    //axe coordinates
    int axeLength{50};
    int axeX{400};
    int axeY{0};
    int direction{10};

    //axe edges
    int lAxeX{axeX};
    int rAxeX{axeX + axeLength};
    int uAxeY{axeY};
    int bAxeY{axeY + axeLength};


    //Collision Bool
    bool collisionWithAxe =
        (bAxeY >= uCircleY) &&
        (uAxeY <= bCircleY) &&
        (lAxeX <= rCircleX) &&
        (rAxeX >= lCircleX);

    SetTargetFPS(60);
    
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
       

        if (collisionWithAxe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else {
        //Game logic begins

        // Update edges
        lCircleX = circleX - circleRadius;
        rCircleX = circleX + circleRadius;
        uCircleY = circleY - circleRadius;
        bCircleY = circleY + circleRadius;
        lAxeX = axeX;
        rAxeX = axeX + axeLength;
        uAxeY = axeY;
        bAxeY = axeY + axeLength;

        // update collision
        collisionWithAxe =
            (bAxeY >= uCircleY) &&
            (uAxeY <= bCircleY) &&
            (lAxeX <= rCircleX) &&
            (rAxeX >= lCircleX);

        DrawCircle(circleX,circleY,circleRadius,BLUE);
        DrawRectangle(axeX,axeY, axeLength,axeLength, RED);
        //move the axe
        axeY += direction;
        if (axeY > height || axeY < 0) 
        {
            direction = -direction;
        };

        if (IsKeyDown(KEY_D) && circleX < width)
        {
            circleX += 10;
        };
        if (IsKeyDown(KEY_A) && circleX > 0)
        {
            circleX -= 10;
        };
        };
    

        //game logic ends
        EndDrawing();
    }
   

    
}