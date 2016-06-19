#include "red_bird.h"

red_bird::red_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : Bird(x, y, radius, timer, pixmap, world, scene){
}

void red_bird::skill(){
    setLinearVelocity(b2Vec2(50, 0));
    //set_transform(b2Vec2(5.0, 8.5), 0.0);
}
