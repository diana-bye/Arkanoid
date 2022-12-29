#include "game.h"
#include <QTimer>

Game::Game(QWidget *parent) {
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 850, 700);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(850, 700);
}

void Game::displayMainMenu() {
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Arkanoid"));
    QFont titleFont("comic sans", 50, 700);
    titleText->setDefaultTextColor(QString("#8B7355"));
    titleText->setFont(titleFont);

    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

void Game::gameOver() {
    QString message;
    if (cellBoard->cellsAlive == 0)
        message = "WIN!!!";
    else
        message = "LOSE";
    displayGameOverWindow(message);
}

void Game::displayGameOverWindow(QString textToDisplay) {
    plate->timer->stop();
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0,0,1024,768,Qt::black,0.65);
    // draw panel
    drawPanel(200,184,400,400,Qt::lightGray,0.75);

    // create playAgain button
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(300,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create menu button
    Button* menu = new Button(QString("Menu"));
    menu->setPos(300,375);
    scene->addItem(menu);
    connect(menu,SIGNAL(clicked()),this,SLOT(toMenu()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(300,450);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create text annoucning win or lose
    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(370,225);
    overText->setDefaultTextColor(Qt::red);
    overText->setFont(QFont("Monospace", 16, 700));
    scene->addItem(overText);
}

void Game::start() {
    // clear the scene
    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    // create a platform
    plate = new Platform();
    plate->setPos(scene->width()/2-plate->boundingRect().width()/2, 666);
    // make platform focusable
    plate->setFlag(QGraphicsItem::ItemIsFocusable);
    plate->setFocus();
    // add the platform to scene
    scene->addItem(plate);
    // create timer for plate moving
    plateTimer = new QTimer();
    connect(plateTimer,SIGNAL(timeout()), plate, SLOT(keyPressEvent));
    plateTimer->start(50);

    // create a ball
    ball = new Ball();
    ball->setPos(scene->width()/2-ball->boundingRect().width()/2, 666-ball->boundingRect().height());
    scene->addItem(ball);

    // create a health
    health = new Health();
    // add the health to scene
    scene->addItem(health);
    health->setPos(13, 4);

    // create cells
    cellBoard = new CellBoard();
    cellBoard->placeCells(65, 40, 20, 8);
}

void Game::restartGame() {
    cellBoard->getCells().clear();
    scene->clear();
    start();
}

void Game::toMenu(){
    cellBoard->getCells().clear();
    scene->clear();
    displayMainMenu();
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity) {
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}
