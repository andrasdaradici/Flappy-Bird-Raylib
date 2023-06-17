#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    const int screenWidth = 288;
    const int screenHeight = 512;
    int Block1X = 0;
    int Block2X = 336;
    
    int Pipe1X = 300;
    int Pipe1Y = 330;
    int Pipe2X = 500;
    int Pipe2Y = 330;
    int Pipe3X = 700;
    int Pipe3Y = 330;
    int gap = 90;
    int Scene = 0;
    
    float PlayerY = 256;
    
    Image WindowLogo = LoadImage("graphics/favicon.png");
    
    InitWindow(screenWidth, screenHeight, "Flappy Bird - Raylib");
    SetWindowIcon(WindowLogo);
    
    Image baseI = LoadImage("graphics/base.png");
    Texture2D base = LoadTextureFromImage(baseI);
    Image backgroundI = LoadImage("graphics/background.png");
    Texture2D background = LoadTextureFromImage(backgroundI);
    Image pipedownI = LoadImage("graphics/pipedown.png");
    Texture2D pipeDown = LoadTextureFromImage(pipedownI);
    Image pipeupI = LoadImage("graphics/pipeup.png");
    Texture2D pipeUp = LoadTextureFromImage(pipeupI);

    Image bird1I = LoadImage("graphics/Bird_1.png");
    Texture2D bird1 = LoadTextureFromImage(bird1I);
    Image bird2I = LoadImage("graphics/Bird_2.png");
    Texture2D bird2 = LoadTextureFromImage(bird2I);
    Image bird3I = LoadImage("graphics/Bird_3.png");
    Texture2D bird3 = LoadTextureFromImage(bird3I);
    Texture2D CurText;
    Image goI = LoadImage("graphics/gameover.png");
    Texture2D go = LoadTextureFromImage(goI);
    
    Image messageI = LoadImage("graphics/message.png");
    Texture2D message = LoadTextureFromImage(messageI);
    
    Image creditI = LoadImage("graphics/credits.png");
    Texture2D credits = LoadTextureFromImage(creditI);
    
    InitAudioDevice(); 
    
    Sound flap = LoadSound("audio/wing.ogg");
    Sound hit = LoadSound("audio/hit.ogg");
    Sound point = LoadSound("audio/point.ogg");
    UnloadImage(baseI);
    UnloadImage(backgroundI);
    UnloadImage(pipedownI);
    UnloadImage(pipeupI);
    UnloadImage(bird1I);
    UnloadImage(bird2I);
    UnloadImage(bird3I);
    UnloadImage(goI);
    UnloadImage(messageI);
    SetTargetFPS(60);
    
    bool Dead = false;
    bool Enviro = false;
    bool Pressed = true;
    bool DidHit = false;
    
    int framesCounter;
    
    bool wait = false;
    
    int score = 0;
    int best = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();

            if(Scene == 0)
            {
                CurText = bird1;
                ClearBackground(RAYWHITE);
                
                Pipe1X = 300;
                Pipe2X = 500;
                Pipe3X = 700;
                
                DrawTexture(background, 0, 0, WHITE);
                
                PlayerY = 256;
                DrawTexture(CurText, 127, PlayerY, WHITE);
                
                DrawTexture(base, Block1X, 400, WHITE);
                DrawTexture(base, Block2X, 400, WHITE);
                
                Pipe1Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                Pipe2Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                Pipe3Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) Scene = 1;
                Dead = false;
                Enviro = true;
                wait = false;
                Block1X -= 1;
                Block2X -= 1;
                DrawTexture(base, Block1X, 400, WHITE);
                DrawTexture(base, Block2X, 400, WHITE);
                
                DrawTexture(message, 52, 88, WHITE);
                DrawTexture(credits, 48, 380, WHITE);
                if(Block1X <= -336)
                {
                    Block1X = 336;
                }
                if(Block2X <= -336)
                {
                    Block2X = 336;
                }
                
            }
            if(Scene == 1)
            {
                if(score > best)
                {
                    best = score;
                }
                if(Pipe1X < 127 && Pipe1X >= 126)
                {
                    PlaySound(point);
                    score++;                    
                }
                if(Pipe2X < 127 && Pipe2X >= 126)
                {
                    PlaySound(point); 
                    score++;
                }
                if(Pipe3X < 127 && Pipe3X >= 126)
                {
                    PlaySound(point); 
                    score++;
                }
                if(Pipe1X <= 158 && Pipe1X >= 127-34)
                {
                    if(PlayerY >= Pipe1Y-24)
                    {
                        Enviro = false;
                        if(DidHit == false)
                        {
                            PlaySound(hit); 
                            DidHit = true;
                        }
                    }
                    if(PlayerY <= Pipe1Y-gap)
                    {
                        Enviro = false;
                        if(DidHit == false)
                        {
                            PlaySound(hit); 
                            DidHit = true;
                        }                       
                    }
                    
                    //
                }
                
                if(Pipe2X <= 158 && Pipe2X >= 127-34)
                {
                    if(PlayerY >= Pipe2Y-24)
                    {
                        Enviro = false;
                        if(DidHit == false)
                        {
                            PlaySound(hit); 
                            DidHit = true;
                        }
                    }
                    if(PlayerY <= Pipe2Y-gap)
                    {
                        Enviro = false;
                        if(DidHit == false)
                        {
                            PlaySound(hit); 
                            DidHit = true;
                        }
                    }
                    
                    //
                }
                
                if(Pipe3X <= 158 && Pipe3X >= 127-34)
                {
                    if(PlayerY >= Pipe3Y-24)
                    {
                        Enviro = false;
                        if(DidHit == false)
                        {
                            PlaySound(hit); 
                            DidHit = true;
                        }
                    }
                    if(PlayerY <= Pipe3Y-gap)
                    {
                        Enviro = false;   
                        if(DidHit == false)
                        {
                            PlaySound(hit); 
                            DidHit = true;
                        }                       
                    }
                    
                    //
                }
                
                if(PlayerY >= 376)
                {
                    Dead = true;
                    Enviro = false;
                    if(DidHit == false)
                    {
                        PlaySound(hit); 
                        DidHit = true;
                    }
                }
                
                if(Dead == false)
                {
                    if(wait == false)
                    {
                        PlayerY+=2; 
                    }
                    else
                    {
                        framesCounter++;

                        // Every two seconds (120 frames) a new random value is generated
                        if (((framesCounter/2)%2) == 1)
                        {
                            CurText = bird1;
                            //wait = false;
                            //framesCounter = 0;
                        }
                        if (((framesCounter/4)%2) == 1)
                        {
                            CurText = bird2;
                            //wait = false;
                            //framesCounter = 0;
                        }
                        if (((framesCounter/6)%2) == 1)
                        {
                            CurText = bird3;
                            //wait = false;
                            //framesCounter = 0;
                        }
                        if (((framesCounter/8)%2) == 1)
                        {
                            CurText = bird2;
                            //wait = false;
                            //framesCounter = 0;
                        }
                        if (((framesCounter/10)%2) == 1)
                        {
                            CurText = bird1;
                            wait = false;
                            framesCounter = 0;
                        }
                    }
                       
                }
                if(Enviro == true)
                {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && Pressed == false) 
                    {
                        PlayerY -= 40;
                        PlaySound(flap);
                        wait = true;
                        Pressed = true;
                    }
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
                    {
                        //PlayerY -= 20;
                        Pressed = false;
                    }
                    
                    Block1X -= 1;
                    Block2X -= 1;
                
                    Pipe1X -= 1;
                    Pipe2X -= 1;
                    Pipe3X -= 1;
                }
                
                ClearBackground(RAYWHITE);
                DrawTexture(background, 0, 0, WHITE);
                
                
                
                if(Block1X <= -336)
                {
                    Block1X = 336;
                }
                if(Block2X <= -336)
                {
                    Block2X = 336;
                }
                
                if(Pipe1X <= -52)
                {
                    Pipe1X = Pipe3X+200;
                    Pipe1Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                }
                if(Pipe2X <= -52)
                {
                    Pipe2X = Pipe1X+200;
                    Pipe2Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                }
                if(Pipe3X <= -52)
                {
                    Pipe3X = Pipe2X+200;
                    Pipe3Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                }
                
                DrawTexture(pipeUp, Pipe1X, Pipe1Y, WHITE);
                DrawTexture(pipeDown, Pipe1X, Pipe1Y-gap-320, WHITE);
                
                DrawTexture(pipeUp, Pipe2X, Pipe2Y, WHITE);
                DrawTexture(pipeDown, Pipe2X, Pipe2Y-gap-320, WHITE);
                
                DrawTexture(pipeUp, Pipe3X, Pipe3Y, WHITE);
                DrawTexture(pipeDown, Pipe3X, Pipe3Y-gap-320, WHITE);
                
                DrawTexture(base, Block1X, 400, WHITE);
                DrawTexture(base, Block2X, 400, WHITE);
                
                DrawText(TextFormat("SCORE: %i", score), 1, 1, 20, BLACK);
                DrawText(TextFormat("SCORE: %i", score), 0, 0, 20, WHITE);
                DrawText(TextFormat("BEST: %i", best), 1, 21, 20, BLACK);                
                DrawText(TextFormat("BEST: %i", best), 0, 20, 20, WHITE);
                
                DrawTexture(CurText, 127, PlayerY, WHITE);
                
                if(Dead)
                {
                    DrawTexture(go, 48, 25, WHITE);
                    DrawTexture(message, 52, 88, WHITE);
                    DrawTexture(credits, 48, 380, WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && Pressed == false) 
                    {
                        score = 0;
                        Dead = false;
                        Enviro = true;
                        PlayerY = 256;
                        Pressed = true;
                        DidHit = false;
                        Pipe1X = 300;
                        Pipe2X = 500;
                        Pipe3X = 700;
                        Pipe1Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                        Pipe2Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                        Pipe3Y = GetRandomValue(100, 300) + GetRandomValue(10, 20);
                    }
                    if (IsKeyUp(KEY_SPACE)) 
                    {
                        //PlayerY -= 20;
                        Pressed = false;
                    }
                }
                
            }
            

        EndDrawing();
    }
    UnloadTexture(base);

    CloseWindow();

    return 0;
}