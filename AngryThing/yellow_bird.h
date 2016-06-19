#ifndef YELLOW_BIRD_H
#define YELLOW_BIRD_H

#include "gameitem.h"
#include "bird.h"


class yellow_bird : public Bird{
public:
    yellow_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // YELLOW_BIRD_H
