#include <raylib.h>
#include <iostream>
#include "grid.hpp"
#include "simulation.hpp"

/*
    Rules of Conway's Game of Life :

    1.Underpopulation : A live cell with fewer than two live neighbours die

    2.Stasis : Alive cell with two or three live neighbours lives on to the next neighbour
    
    3.Overpopulation : A live cell with more than three live neighbours dies

    4.Reproduction : A dead cell with exactly three live neighbours becomes a live cell

*/

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 900;
    const int CELL_SIZE = 10;
    //Lower fps to clearly observe the life cycle stages...
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);


    //Simulation Loop
    while(WindowShouldClose() == false) {

        //1.Event Handling...
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, column);
        }
        if(IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Conway's Game of Life is Running...");
        }
        else if(IsKeyPressed(KEY_SPACE)) 
        {
            simulation.Stop();
            SetWindowTitle("Conway's Game of Life is Paused...");
        }
        else if(IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if(IsKeyPressed(KEY_S)) {
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

        //2.Updating the state...
        simulation.Update();

        //3.Drawing...
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}