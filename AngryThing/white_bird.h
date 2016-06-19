#ifndef WHITE_BIRD_H
#define WHITE_BIRD_H

#include "gameitem.h"
#include "bird.h"


class white_bird : public Bird{
public:
    white_bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // WHITE_BIRD_H
