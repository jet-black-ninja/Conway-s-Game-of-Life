#pragma once
#include <vector>

class Grid{
    public:
        Grid(int width, int height, int cellSize)
        :rows(height/cellSize) , columns(height/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)){};
        void Draw();
        void setValue(int row, int column, int value);
        int getValue ( int row, int column );
        int getRows(){return rows;}
        int getColumns(){return columns;}
        void FillRandom();
        void Clear();
        void toggleCell(int row , int col);
    private:
    int rows; 
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
    bool isWithinBounds(int row, int column);
};