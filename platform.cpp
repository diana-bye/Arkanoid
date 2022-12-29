#include "platform.h"
#include "game.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

extern Game* game;

Platform::Platform(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    // set graphic
    setPixmap(QPixmap(":/images/platform.png"));
}

void Platform::keyPressEvent(QKeyEvent* event) {
    // move the platform left and right
    if (event->key() == Qt::Key_Left) {
        pdx = -15;
        if (pos().x() + pdx > 0) {
            if (game->ball != NULL && !game->ball->isBallMove)
                game->ball->setX(game->ball->x()+pdx);
            setX(x()+pdx);
        }
        pdx = 0;
    }
    if (event->key() == Qt::Key_Right) {
        pdx = 15;
        if ((pos().x() + boundingRect().width() + pdx) < 850) {
            // move ball with plate
            if (game->ball != NULL && !game->ball->isBallMove)
                game->ball->setX(game->ball->x()+pdx);
            // move plate
            setX(x()+pdx);
        }
        pdx = 0;
    }
    if (event->key() == Qt::Key_Space && !game->ball->isBallMove) {
        timer = new QTimer(game->ball);
        connect(timer,SIGNAL(timeout()),game->ball, SLOT(move()));

        // start the timer
        timer->start(10);
        game->ball->isBallMove = true;
    }
}
