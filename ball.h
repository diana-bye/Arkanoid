#ifndef BALL_H
#define BALL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Ball: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Ball(QGraphicsItem * parent=0);
    bool isBallMove = false;
public slots:
    void move();
private:
    int dx = 2;
    int dy = -3;
};

#endif // BALL_H
