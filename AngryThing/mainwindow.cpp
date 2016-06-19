#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    //enable the event Filter
    qApp->installEventFilter(this);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/BG").scaled(960, 540));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//disable scrollbar (horizontal)
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//disable scrollbar (vertical)
    instruct = new QLabel(this);
    instruct->setStyleSheet("color:black; background-color: transparent; font: bold 12px;");
    instruct->setText("Press 's' to increase the speed \nPress 'space' to activate special power \nPress left mouse button to shoot \nThe angle was set to 45`");
    instruct->setGeometry(50, 0, 300, 60);
    instruct->show();

    score = new QLabel(this);
    score->setStyleSheet("color:black; background-color: transparent; font: bold 24px;");
    score->setText("Score = 0");
    score->setGeometry(400, 0, 200, 30);
    score->show();

    speed1 = new QLabel(this);
    speed1->setStyleSheet("color:black; background-color: transparent; font: bold 24px;");
    speed1->setText("Speed = 1");
    speed1->setGeometry(400, 31, 300, 30);
    speed1->show();
}

MainWindow::~MainWindow(){
    delete ui;
}

int num = 0 , num1 = 0 , count1 = 0 , count2 = 0 , count3 = 0 , skill1 = 0 , skill2 = 0, skill3 = 0 , skill4 = 0 , speed = 1 , score1 = 0;

void MainWindow::showEvent(QShowEvent *){
    build();
    resetValue();
    //timer
    connect(&timer, SIGNAL(timeout()), this, SLOT(tick()));
    connect(this, SIGNAL(quitGame()), this, SLOT(QUITSLOT()));
    timer.start(100/6);
}

void MainWindow::resetValue()
{
    score1 = 0 ,num = 0 , count1 = 0 , count2 = 0 , count3 = 0 ,skill1 = 0 , skill2 = 0, skill3 = 0 , skill4 = 0 , speed = 1;
}

void MainWindow::build()
{
    //setting QGraphicsScene
    scene = new QGraphicsScene(0, 0, 960, 540);
    ui->graphicsView->setScene(scene);

    //create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    //setting Size
    GameItem::setGlobalSize(QSizeF(32.0f, 18.0f),size());

    //create ground
    itemList.push_back(new Land(16.0f, 1.5f, 32.0f, 3.0f, QPixmap(":/ground.png").scaled(960,90), world, scene));

    //create bird
    red = new red_bird(3.0f, 6.0f, 0.5f, &timer, QPixmap(":/bird_red").scaled(30 , 30), world, scene);
    itemList.push_back(red);

    yellow = new yellow_bird(3.0f, 8.0f, 0.5f, &timer, QPixmap(":/bird_yellow").scaled(30, 30), world, scene);
    itemList.push_back(yellow);

    blue = new blue_bird(3.0f, 10.0f, 0.5f, &timer, QPixmap(":/bird_blue").scaled(30, 30), world, scene);
    itemList.push_back(blue);

    white = new white_bird(3.0f, 12.0f, 0.5f, &timer, QPixmap(":/bird_white").scaled(30, 30), world, scene);
    itemList.push_back(white);

    n1 = new Pig(17.5f, 13.0f, 0.5f, &timer, QPixmap(":/enemy").scaled(30, 30), world, scene);
    itemList.push_back(n1);

    n2 = new Pig(21.0f, 13.0f, 0.5f, &timer, QPixmap(":/enemy").scaled(30, 30), world, scene);
    itemList.push_back(n2);

    n3 = new Pig(24.5f, 13.0f, 0.5f, &timer, QPixmap(":/enemy").scaled(30, 30), world, scene);
    itemList.push_back(n3);

    //set bird's velocity
    //bird_1->setLinearVelocity(b2Vec2(20, 8));

    //create brick
    itemList.push_back(new brick(17.5f, 5.0f, 1.0f, 4.0f, &timer, QPixmap(":/brick_zhi").scaled(30, 120), world, scene));
    itemList.push_back(new brick(21.0f, 5.0f, 1.0f, 4.0f, &timer, QPixmap(":/brick_zhi").scaled(30, 120), world, scene));
    itemList.push_back(new brick(24.5f, 5.0f, 1.0f, 4.0f, &timer, QPixmap(":/brick_zhi").scaled(30, 120), world, scene));

    itemList.push_back(new brick(19.0f, 7.5f, 4.0f, 1.0f, &timer, QPixmap(":/brick_heng").scaled(120, 30), world, scene));
    itemList.push_back(new brick(23.0f, 7.5f, 4.0f, 1.0f, &timer, QPixmap(":/brick_heng").scaled(120, 30), world, scene));

    itemList.push_back(new brick(17.5f, 10.0f, 1.0f, 4.0f, &timer, QPixmap(":/brick_zhi").scaled(30, 120), world, scene));
    itemList.push_back(new brick(21.0f, 10.0f, 1.0f, 4.0f, &timer, QPixmap(":/brick_zhi").scaled(30, 120), world, scene));
    itemList.push_back(new brick(24.5f, 10.0f, 1.0f, 4.0f, &timer, QPixmap(":/brick_zhi").scaled(30, 120), world, scene));

    restartgg = new QPushButton;
    restartgg->setText("RESTART");
    restartgg->setGeometry(740, 10, 100, 50);
    restartgg->setStyleSheet("color:black; background-color: transparent; font: bold 20px;");
    connect(restartgg, SIGNAL(clicked(bool)), this, SLOT(restartGame()));
    scene->addWidget(restartgg);
}



bool MainWindow::eventFilter(QObject *, QEvent *event){

    if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        if (mouse_event->button() == Qt::LeftButton){
            //std::cout << "Left Button Press!" << std::endl ;
            count1 ++;
            if(count1 == 5)
            {
                if( num == 0)
                {
                    white->setLinearVelocity( b2Vec2(speed*2.0f ,speed*2.0f) );
                    num ++;
                    count1 = 0; speed = 1;
                }
                else
                {
                    if( num == 1 )
                    {
                        //if(num1 == 0) num1++;
                        blue->setLinearVelocity( b2Vec2(speed*2.0f ,speed*2.0f) );
                        num ++;
                        count1 = 0; speed = 1;
                    }
                    else
                    {
                        if( num == 2 )
                        {
                            //if(num1 == 1) num1++;
                            yellow->setLinearVelocity( b2Vec2(speed*2.0f ,speed*2.0f) );
                            num ++;
                            count1 = 0; speed = 1;
                        }
                        else
                        {
                            if( num == 3 )
                            {
                                //if(num1 == 2) num1++;
                                red->setLinearVelocity( b2Vec2(speed*2.0f ,speed*2.0f) );
                                num ++;
                                count1 = 0; speed = 1;
                            }
                        }
                    }
                 }
             }
        }
        else if (mouse_event->button() == Qt::RightButton){
            //std::cout << "Right Button Press!" << std::endl ;

        }
    }
    else if(event->type() == QEvent::MouseButtonRelease){

        //std::cout << "Release !" << std::endl ;


    }


    else if(event->type() == QEvent::MouseMove){
        //std::cout << "Move !" << std::endl ;
    }
    else if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key_event = static_cast<QKeyEvent*>(event);
        //sdferewrewfws
        if(key_event->key() == Qt::Key_Space)
        {
            count2++;
            if( count2 == 5 )
            {
                if (num == 0) count2 = 0;
                if( num == 1 )
                {
                    if(skill1 == 0)
                    {
                        white->skill();
                        skill1 = 1;
                    }
                    count2 = 0;

                }
                else
                {
                    if( num == 2 )
                    {
                        if(skill2 == 0)
                        {
                            blue->skill();
                            skill2 = 1;
                        }
                        count2 = 0;

                    }
                    else
                    {
                        if( num == 3 )
                        {
                            if(skill3 == 0)
                            {
                                yellow->skill();
                                skill3 = 1;
                            }
                            count2 = 0;

                        }
                        else
                        {
                            if( num == 4 )
                            {
                                if(skill4 == 0)
                                {
                                    red->skill();
                                    skill4 = 1;
                                }
                                count2 = 0;

                            }
                        }
                    }
                }
            }
        }
        else if(key_event->key() == Qt::Key_S)
        {
            count3++;
            if( count3 == 5)
            {
                speed++;
                count3 = 0;
            }
        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *){
    //close event
    emit quitGame();
}

void MainWindow::tick(){
    world->Step(1.0/60.0,6,2);
    scene->update();
    if (n1->getLinearVelocity().x + n1->getLinearVelocity().y > 1)
    {
        n1->setPos(b2Vec2(100,10));
        score1 += 1000;
    }
    if (n2->getLinearVelocity().x + n2->getLinearVelocity().y > 1.5)
    {
        n2->setPos(b2Vec2(100,10));
        score1 += 1000;
    }
    if (n3->getLinearVelocity().x + n3->getLinearVelocity().y > 1.5)
    {
        n3->setPos(b2Vec2(100,10));
        score1 += 1000;
    }
    score->setText("Score = " + QString::number(score1));
    speed1->setText("Speed = " + QString::number(speed));
}

void MainWindow::QUITSLOT(){
    //send output signal (for debug)
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::restartGame(){
    itemList.clear();

    build();
    resetValue();
}
