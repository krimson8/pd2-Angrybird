#ifndef RED_BIRD_H
#define RED_BIRD_H

#include "gameitem.h"
#include "bird.h"


class red_bird : public Bird{
public:
    red_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // RED_BIRD_H
