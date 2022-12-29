#include "button.h"


Button::Button(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent) {
    // draw the rect
    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QString("#548B54"));
    setPen(Qt::NoPen);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name, this);
    text->setDefaultTextColor(Qt::white);
    text->setFont(QFont("Monospace", 16, 700));
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // change color to green
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // change color to dark green
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QString("#6E8B3D"));
    setBrush(brush);
}
