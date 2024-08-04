#include <raylib.h>
#include "grid.hpp"
void Grid::Draw()
{
    for(int row = 0; row<rows; row++){
        for(int column = 0  ; column< columns; column++){
            Color color = cells [row][column] ?Color{0, 255, 0 , 255} : Color{55, 55, 55,255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize-1, cellSize-1, color);
        }
    }
}

void Grid::setValue(int row, int column, int value)
{
    if(isWithinBounds(row, column))
        cells[row][column]=value;
    
}

int Grid::getValue(int row, int column)
{
    if(isWithinBounds(row,column)){
        return cells[row][column];
    }
    return 0;
}

bool Grid::isWithinBounds(int row, int column)
{
    if(row>=0 && row< rows && column >=0 && column<columns){
        return true;
    }
    return false;
}

void Grid::FillRandom()
{
    for(int row = 0 ; row<rows ; row++){
        for(int col = 0; col < columns ; col++){
            int randomValue = GetRandomValue(0,4);
            cells[row][col]= (randomValue==4)?1:0;
            
        }
        
    }
}

void Grid::Clear()
{
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            cells[row][column] = 0;
        }
    }
}

void Grid::toggleCell(int row, int col)
{
    if(isWithinBounds(row,col)){
        cells[row][col]= !cells[row][col];
    }

}