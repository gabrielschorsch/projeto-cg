#ifndef RECT_H
#define RECT_H

#include "object.h"

class Rect : public Object
{

private:
    QList<QPoint> points;
public:
    Rect(int x,int y, int w, int h);
    Rect(QList<QPoint> points);
    virtual void draw(QPainter* pen);
};

#endif // RECT_H
