#include "cell.h"

Cell::Cell(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    // draw graphics
    setPixmap(QPixmap(":/images/cell.png"));
}
