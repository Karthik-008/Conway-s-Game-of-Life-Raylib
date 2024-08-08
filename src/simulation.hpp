#pragma once
#include "grid.hpp"

/*
    Reduced Rules :

    1.The cell dies if there are less than 2 live neighbours or more than 3 live neighbours.

    2.If cell is dead , it comes alive if the live neighbours are 3
*/

class Simulation
{
    public:
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false){};

        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbours(int row, int column);
        void Update();
        bool IsRunning() {return run;};
        void Start() {run = true;};
        void Stop() {run = false;};
        void ClearGrid();
        void CreateRandomState();
        void ToggleCell(int row, int column);

    private:
        Grid grid;
        Grid tempGrid;
        bool run;
};