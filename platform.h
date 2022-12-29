#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Platform : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Platform(QGraphicsItem* parent=0);
    QTimer * timer;
    int pdx;
public slots:
    void keyPressEvent(QKeyEvent* event);
};

#endif // PLATFORM_H
