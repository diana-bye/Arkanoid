#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem* parent): QGraphicsTextItem(parent) {
    health = 5;

    setPlainText(QString(QString::number(health)));
    setDefaultTextColor(Qt::darkRed);
    setFont(QFont("times", 12));
}

void Health::decrease() {
    health--;
    setPlainText(QString(QString::number(health)));
}

int Health::getHealth()
{
    return health;
}
