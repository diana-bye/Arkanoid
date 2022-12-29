#include "ball.h"
#include "platform.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "game.h"

extern Game* game;

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    // draw graphics
    setPixmap(QPixmap(":/images/ball.png"));
}

void Ball::move() {
    setPos(x() + dx, y() + dy);
    //int left, right, top, bottom, middlex, middley;
    // get a list of all the items currently colliding with this ball
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Cell)) {
            qreal x = pos().x() - colliding_items[i]->x();
            qreal y = pos().y() - colliding_items[i]->y();
            if  (abs(x) > abs(y)) {
                dx *= -1;
            }
            else {
                dy *= -1;
            }
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            if (--game->cellBoard->cellsAlive == 0)
                game->gameOver();
            break;
         }
    }

    if (x() + dx >= game->plate->x() && x() + dx <= (game->plate->x() + game->plate->boundingRect().width()) &&
            y() + dy + boundingRect().height() == game->plate->y()) {
        if (dx >= 0 && game->plate->pdx > 0)
            dx += 1;
        else if (dx <= 0 && game->plate->pdx > 0)
            dx -= 1;
        else if (dx >= 0 && game->plate->pdx < 0)
            dx -= 1;
        else if (dx <= 0 && game->plate->pdx < 0)
            dx += 1;
        dy *= -1;
    }
    else if (y() + dy + boundingRect().height() > 700) {
        // decrease the health
        game->health->decrease();
        if (game->health->getHealth() == 0) {
            game->gameOver();
            return;
        }
        // set ball on start position
        setPos(game->plate->x()+game->plate->boundingRect().width()/2-boundingRect().width()/2, 666-boundingRect().height());
        // stop the ball
        isBallMove = false;
        game->plate->timer->stop();
        dy *= -1;
        dx = 2;
        return;
    }
    else if (y() + dy < 0) {
        dy *= -1;
    }
    else if (x() + dx < 0 || x() + dx + boundingRect().width() > 850) {
        dx *= -1;
    }
}
