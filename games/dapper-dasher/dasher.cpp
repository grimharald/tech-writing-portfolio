#include "raylib.h"

int main()
{
    //Window dimensions
    const int windWidth{512};
    const int windHeight{380};

    //Initialise the window
    InitWindow(windWidth,windHeight,"Dapper Dasher");
    
    //gravity acelartion, pixels/s/s
    const int gravity{1'000};

    //scarfy
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec; 
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = (windWidth / 2) - (scarfyRec.width / 2);
    scarfyPos.y =  windHeight - scarfyRec.height;

    int velocity{0};

    // animation frame
    int frame{};

    // time before animation frame updates
    const float updateTime{1.0 / 12.0};
    float runningTime{};

    //air check
    bool isInAir{};


    // jumpvel in poxels/s
    const int jumpVelocity{-600};

    SetTargetFPS(60);

   
    


    while (!WindowShouldClose())
    {

        //Delta Time, time since last frame
        const float dT{GetFrameTime()};
      
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        //ground check
        if (scarfyPos.y >= windHeight - scarfyRec.height) {
            velocity = 0;
            isInAir = false;
        } 
        else {
            //rectangle is in the air
            //apply gravity
            velocity += gravity * dT;
            isInAir = true;
        }
        // update position
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVelocity;
        };

        scarfyPos.y += velocity * dT;
        
       // Update runninTime
        runningTime += dT;

        //Update animation frame
        if(runningTime >= updateTime) {
            runningTime = 0.0;
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if (frame > 5) {
                frame = 0;
         }
        };

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        //stop drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
    
}