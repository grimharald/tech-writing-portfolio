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
    //window array.
    double windowDimensions[2];
    windowDimensions[0] = 512;
    windowDimensions[1] = 380;


    //Initialise the window
    InitWindow(windowDimensions[0],windowDimensions[1],"Dapper Dasher");
    
    //gravity acelartion, pixels/s/s
    const int gravity{1'000};


    //nebula variables
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");


    //animdata for nebula
    const int sizeOfNebulae{10};
    AnimData nebulae[sizeOfNebulae]{};
        for (int i = 0; i<sizeOfNebulae; i++) {
            nebulae[i].rec.x = 0.0;
            nebulae[i].rec.y = 0.0;
            nebulae[i].rec.width = nebula.width/8;
            nebulae[i].rec.height = nebula.height/8;
            nebulae[i].pos.y = windowDimensions[1] - nebula.height / 8;
            nebulae[i].runningTime = 0.0;
            nebulae[i].updateTime = 1.0/16.0;
            nebulae[i].pos.x = windowDimensions[0] + i*300;
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
    scarfyData.pos.x = (windowDimensions[0]/2) - (scarfyData.rec.width/2);
    scarfyData.pos.y = windowDimensions[0]/2 - scarfyData.rec.height;
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
        if (scarfyData.pos.y >= windowDimensions[1] - scarfyData.rec.height) {
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


        for (int i=0; i<sizeOfNebulae; i++) {
            // update each nebula's position
            nebulae[i].pos.x += nebVel * dT;
        }
        
        //update scarfy position 
        scarfyData.pos.y += velocity * dT;

        // Update runninTime
        scarfyData.runningTime += dT;

        //Update scarfy animation frame
        if (!isInAir)
            {if(scarfyData.runningTime >= scarfyData.updateTime) {
                scarfyData.runningTime = 0.0;
                scarfyData.rec.x = scarfyData.frame * scarfyData.rec.width;
                scarfyData.frame++;
         nebulae[0].runningTime += dT;
         if (nebulae[0].runningTime >= nebulae[0].updateTime)
         {
             nebulae[0].runningTime = 0.0;
             nebulae[0].rec.x = nebulae[0].frame * nebulae[0].rec.width;
             nebulae[0].frame++;
             if (nebulae[0].frame > 8)
             {
                 nebulae[0].frame = 0;
             };
         };
         if (scarfyData.frame > 5)
         {
             scarfyData.frame = 0;
         };
        };
        };


        // for loop animation
        for (int i = 0; i < sizeOfNebulae; i++) {
         //update nebula animation frame
        nebulae[i].runningTime += dT;
        if (nebulae[i].runningTime >= nebulae[i].updateTime) {
        nebulae[i].runningTime = 0.0;
        nebulae[i].rec.x = nebulae[1].frame * nebulae[i].rec.width;
        nebulae[i].frame++;
        if (nebulae[i].frame > 7)
        {
         nebulae[i].frame = 0;
        };
        };   
        }

        for (int i=0; i<sizeOfNebulae; i++) {
        // draw nebulae
        DrawTextureRec(nebula, nebulae[i].rec, nebulae[i].pos, WHITE);
        };

        
        //draw scarfy
        DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);
        
        //stop drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
    
}