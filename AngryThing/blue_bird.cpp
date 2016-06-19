#include "blue_bird.h"

blue_bird::blue_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : Bird(x, y, radius, timer, pixmap, world, scene){
}

void blue_bird::skill(){
    setLinearVelocity(b2Vec2(0, 0));
    //set_transform(b2Vec2(5.0, 8.5), 0.0);
}
