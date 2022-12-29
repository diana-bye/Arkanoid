#ifndef GAME_H
#define GAME_H

#include "platform.h"
#include "ball.h"
#include "health.h"
#include "button.h"
#include "cellBoard.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>

class Game : public QGraphicsView {
    Q_OBJECT
public:
    // constructors
    Game(QWidget* parent=0);

    // atributes
    QGraphicsScene* scene;
    Platform* plate;
    Ball* ball;
    Health* health;
    CellBoard* cellBoard;

    // timer for platform move
    QTimer* plateTimer;

    // methods
    void displayMainMenu();
    void gameOver();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void displayGameOverWindow(QString textToDisplay);

public slots:
    void start();
    void restartGame();
    void toMenu();
};

#endif // GAME_H
