#ifndef CELLBOARD_H
#define CELLBOARD_H

#include "cell.h"
#include <QList>

class CellBoard {
public:
    CellBoard();
    QList<Cell*> getCells();
    int cellsAlive;
    void placeCells(int x, int y, int cols, int rows);
    void createColumn(int x, int y, int numOfRows);
private:
    QList<Cell*> cells;
};

#endif // CELLBOARD_H
