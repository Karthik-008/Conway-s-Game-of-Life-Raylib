#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbours(int row, int column)
{
    int liveNeighbours = 0;
    std::vector<std::pair<int, int>> neighbourOffsets = 
    {
        {-1, 0},  
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}

    };

    for(const auto& offset : neighbourOffsets) {
        int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbourColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbours += grid.GetValue(neighbourRow, neighbourColumn);
    }
    return liveNeighbours;
}

void Simulation::Update()
{
    if(IsRunning())
    {
        for(int row=0;row<grid.GetRows();row++) 
        {
            for(int col=0;col<grid.GetColumns();col++) 
            {
                int liveNeighbours = CountLiveNeighbours(row, col);
                int cellValue = grid.GetValue(row, col);

                if(cellValue == 1) 
                {
                    if(liveNeighbours > 3 || liveNeighbours < 2) 
                    {
                        tempGrid.SetValue(row, col, 0);
                    }
                    else
                    {
                        tempGrid.SetValue(row, col, 1);
                    }
                }
                else 
                {
                    if(liveNeighbours == 3) 
                    {
                        tempGrid.SetValue(row, col, 1);
                    }
                    else
                    {
                        tempGrid.SetValue(row, col, 0);
                    }
                }
            }
        }
        grid = tempGrid;
    }
    
}

void Simulation::ClearGrid()
{
    if(!IsRunning()) 
    {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if(!IsRunning()) 
    {
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int column)
{
    if(!IsRunning())
    {
        grid.Toggle(row, column);
    }
}
