#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <matrix.h>
#include <QPainter>
#include "point.h"

class Object
{
private:
    Point getObjectCenterPoint();
public:
    QList<Point*> points;
    Object();
    void rotate(int degrees);

    void translate(float dx, float dy);
    virtual void draw(QPainter* pen);
signals:

};

#endif // OBJECT_H
