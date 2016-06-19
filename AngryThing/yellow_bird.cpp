#include "yellow_bird.h"

yellow_bird::yellow_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : Bird(x, y, radius, timer, pixmap, world, scene){
}

void yellow_bird::skill(){
    setLinearVelocity(b2Vec2( 5 , -300 ));
    //set_transform(b2Vec2(5.0, 8.5), 0.0);
}
