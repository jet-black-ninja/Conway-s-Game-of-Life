#include<vector>
#include<utility>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}
void Simulation::setCellValue(int row, int column, int value)
{
    grid.setValue(row, column, value);
}

int Simulation::countLiveNeighbours(int row, int column)
{
    int liveNeighbours = 0;
    std::vector<std::pair<int,int>> neighbourOffset={
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };
    
    for(const auto & offset : neighbourOffset){
        int neighbourRow = (row+offset.first + grid.getRows())%grid.getRows() ;
        int neighbourCol = (column + offset.second + grid.getColumns()) % grid.getColumns();
        liveNeighbours += grid.getValue(neighbourRow, neighbourCol);
    }
    return liveNeighbours;
}

void Simulation::Update()
{
    if(isRunning()){
        for(int row = 0 ; row< grid.getRows() ; row++){
            for(int col = 0 ; col < grid.getColumns() ; col++){
                int liveNeighbours = countLiveNeighbours(row, col);
                int cellValue = grid.getValue(row, col);

                if(cellValue== 1){
                    if(liveNeighbours > 3 || liveNeighbours < 2){
                        tempGrid.setValue(row, col , 0);
                    }else{
                        tempGrid.setValue(row, col , 1);
                    }
                }else {
                    if(liveNeighbours == 3){
                        tempGrid.setValue(row, col, 1);
                    }else{
                        tempGrid.setValue(row, col , 0);
                    }
                }
            }
        }
    
    grid= tempGrid;
    }
}

void Simulation::ClearGrid()
{
    if(isRunning() == false){
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if(isRunning() == false){
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int col)
{
    if(isRunning() == false)
        grid.toggleCell(row,col);
}
