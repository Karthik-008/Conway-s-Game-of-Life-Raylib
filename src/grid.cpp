#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for(int row = 0; row < rows; row++) 
    {
        for(int col = 0; col < columns; col++) 
        {
            Color color = cells[row][col] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};

            //make the rectangle bt 1px small to create grid lines
            DrawRectangle(col*cellSize, row*cellSize, cellSize-1, cellSize-1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    if(IsWithinBounds(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int column)
{
    if(IsWithinBounds(row, column)) {
        return cells[row][column];
    }

    return 0;
}

bool Grid::IsWithinBounds(int row, int column)
{
    if(row >= 0 && row < rows && column >= 0 && column < columns) {
        return true;
    }

    return false;
}

void Grid::FillRandom()
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < columns; col++) 
        {
            int randomValue = GetRandomValue(0, 4);
            cells[row][col] = (randomValue == 4) ? 1 : 0;
        }
    }
}

void Grid::Clear()
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < columns; col++) 
        {
            cells[row][col] =  0;
        }
    }
}

void Grid::Toggle(int row, int column)
{
    if(IsWithinBounds(row, column))
    {
        cells[row][column] = !cells[row][column];
    }
}
