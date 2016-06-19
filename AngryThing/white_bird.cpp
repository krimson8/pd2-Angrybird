#include "white_bird.h"

white_bird::white_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : Bird(x, y, radius, timer, pixmap, world, scene){
}

void white_bird::skill(){
    setLinearVelocity(b2Vec2(2, 30));
    //set_transform(b2Vec2(5.0, 8.5), 0.0);
}
