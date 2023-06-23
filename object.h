#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <matrix.h>
#include <QPainter>
#include <QLine>
#include "point.h"
#include "line.h"

class Object
{
private:
    Point getObjectCenterPoint();
public:
    QList<Point*> points;
    QList<QLine*> lines;
    Object();
    void rotate(int degrees);

    void translate(float dx, float dy);
    virtual void draw(QPainter* pen);
signals:

};

#endif // OBJECT_H
