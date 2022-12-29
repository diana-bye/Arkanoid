#ifndef CELL_H
#define CELL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Cell: public QGraphicsPixmapItem {
public:
    Cell(QGraphicsItem* parent=0);
};

#endif // CELL_H
