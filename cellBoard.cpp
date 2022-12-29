#include "cellBoard.h"
#include "game.h"
extern Game* game;

CellBoard::CellBoard(){
}

QList<Cell *> CellBoard::getCells() {
    return cells;
}

void CellBoard::placeCells(int x, int y, int cols, int rows)
{
    int dx = 36;
    for(size_t i = 0, n = cols; i < n; i++) {
        createColumn(x + i*dx, y, rows);
    }
    cellsAlive = cols * rows;
}

void CellBoard::createColumn(int x, int y, int numOfRows)
{
    // creates a column of Hexes
    for (size_t i = 0, n = numOfRows; i < n; i++){
        Cell* cell = new Cell();
        cell->setPos(x, y+36*i);
        cells.append(cell);
        game->scene->addItem(cell);
    }
}
