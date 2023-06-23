#ifndef POINT_H
#define POINT_H

#include <QPoint>
#include "matrix.h"
#include <QList>


class Point : public QPoint, public Matrix
{

public:

    float x,y,z;
    Point(double x, double y);
    Point(float x, float y);
    Point(double x, double y, double z);
    QList<QPoint> transformPointToQPoint(QList<Point> list);
    QPoint transformPointToQPoint(Point p);

};

#endif // POINT_H
