#ifndef BLUE_BIRD_H
#define BLUE_BIRD_H

#include "gameitem.h"
#include "bird.h"


class blue_bird : public Bird{
public:
    blue_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // BLUE_BIRD_H
