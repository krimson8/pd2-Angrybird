#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>

#include <QCursor>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <blue_bird.h>
#include <red_bird.h>
#include <white_bird.h>
#include <yellow_bird.h>
#include <enemy.h>
#include <brick.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    red_bird *red;
    yellow_bird *yellow;
    blue_bird *blue;
    white_bird *white;
    Pig *n1;
    Pig *n2;
    Pig *n3;
    void build();
    void resetValue();
signals:
    void quitGame();

private slots:
    void tick();
    void QUITSLOT();
    void restartGame();
    void exitGame();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    QLabel *instruct;
    QLabel *score;
    QLabel *speed1;
    QPushButton *restartgg , *exitgg;
};

#endif // MAINWINDOW_H
