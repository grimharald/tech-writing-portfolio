#include "raylib.h"
struct  AnimData
{
    Rectangle rec;
    Vector2 pos;
    int frame; 
    float updateTime;
    float runningTime;
};

int main()
{
    //Window dimensions
    const int windWidth{512};
    const int windHeight{380};

    //Initialise the window
    InitWindow(windWidth,windHeight,"Dapper Dasher");
    
    //gravity acelartion, pixels/s/s
    const int gravity{1'000};


    //nebula variables
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

    //animdata for nebula
    AnimData nebData{
        {0.0, 0.0, nebula.width / 8, nebula.height / 8}, // rectangle rec
        {windWidth, windHeight - nebula.height / 8},     // Vector2 pos
        0,                                               // int frame
        1.0 / 12.0,                                      // float updateTime
        0                                                // float runningTime
    };

    AnimData neb2Data{
        {.0, 0.0, nebula.width / 8, nebula.height / 8}, // rectangle rec
        {windWidth + 300, windHeight - nebula.height / 8}, //Vector2 pos
        0, //int frame
        1.0/16.0, //float updateTime
        0 //float runningTime
        };

    //nebula x velocity in pixels/s
    int nebVel{-200};

    //scarfy variables
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    AnimData scarfyData{};
    scarfyData.rec.width = scarfy.width/6;
    scarfyData.rec.height = scarfy.height;
    scarfyData.rec.x = 0;
    scarfyData.rec.y = 0;
    scarfyData.pos.x = (windWidth/2) - (scarfyData.rec.width/2);
    scarfyData.pos.y = windHeight/2 - scarfyData.rec.height;
    scarfyData.frame = 0;
    scarfyData.updateTime = 1.0/12.0;
    scarfyData.runningTime = 0.0;
    
 

    int velocity{0};

 


    //air check
    bool isInAir{};


    // jumpvel in pixels/s
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
        if (scarfyData.pos.y >= windHeight - scarfyData.rec.height) {
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

        // update nebula position
        nebData.pos.x += nebVel * dT;

        //update nebula 2 position
        neb2Data.pos.x += nebVel * dT;

        // update scarfy position
        scarfyData.pos.y += velocity * dT;
        
       // Update runninTime
        scarfyData.runningTime += dT;

        //Update scarfy animation frame
        if (!isInAir)
            {if(scarfyData.runningTime >= scarfyData.updateTime) {
                scarfyData.runningTime = 0.0;
                scarfyData.rec.x = scarfyData.frame * scarfyData.rec.width;
                scarfyData.frame++;
         nebData.runningTime += dT;
        if (nebData.runningTime >= nebData.updateTime) {
            nebData.runningTime = 0.0;
            nebData.rec.x = nebData.frame * nebData.rec.width;
            nebData.frame++;
            if (nebData.frame > 8) {
                nebData.frame = 0;
            };
        };        if (scarfyData.frame > 5) {
                    scarfyData.frame = 0;
            };
        };
        };

        //update nebula animation frame
        nebData.runningTime += dT;
        if (nebData.runningTime >= nebData.updateTime) {
            nebData.runningTime= 0.0;
            nebData.rec.x = neb2Data.frame * nebData.rec.width;
            nebData.frame++;
            if (nebData.frame> 7) {
                nebData.frame = 0;
            };
        };
        
        neb2Data.runningTime += dT;
        if (neb2Data.runningTime >= neb2Data.updateTime)
        {
            neb2Data.runningTime = 0.0;
            neb2Data.rec.x = neb2Data.frame * neb2Data.rec.width;
            neb2Data.frame++;
            if (neb2Data.frame > 7)
            {
                neb2Data.frame = 0;
            };
        };

        //draw nebula
        DrawTextureRec(nebula, nebData.rec, nebData.pos,WHITE);

        //draw 2nd nebula
        DrawTextureRec(nebula, neb2Data.rec, neb2Data.pos, RED);

        //draw scarfy
        DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);
        
        //stop drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
    
}