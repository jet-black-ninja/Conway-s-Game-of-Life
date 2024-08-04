#include <raylib.h>
#include "simulation.hpp"
int main()
{
    Color grey= Color{29, 29, 29, 255};

    const int screenWidth = 750;
    const int screenHeight = 750;
    const int CELL_SIZE = 25;
    int FPS=12;
    

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(screenWidth, screenHeight, CELL_SIZE);
    

    while (!WindowShouldClose())
    {
        //Event Handling
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y/CELL_SIZE;
            int col = mousePosition.x/CELL_SIZE;
            simulation.ToggleCell(row,col);
        }
        if(IsKeyPressed(KEY_ENTER)) 
        {
            simulation.Start();
            SetWindowTitle("Game of Life is Running ....");
        }
        else if(IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of Life has stopped .");
        }
        else if(IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if(IsKeyPressed(KEY_S))
        {
            if(FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }
        else if(IsKeyPressed(KEY_R))
        {
            
            simulation.CreateRandomState();
        }
        else if(IsKeyPressed(KEY_C))
        {
            
            simulation.ClearGrid();
        }
        //update
        simulation.Update();
        //Draw
        BeginDrawing();
        ClearBackground(grey);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}