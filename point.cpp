#include "point.h"

Point::Point(double x, double y){
    this->x = x;
    this->y = y;

}
Point::Point(float x, float y){
    this->x = x;
    this->y = y;
}
QList<QPoint> Point::transformPointToQPoint(QList<Point> list){
    QList<QPoint> newList;
    for(Point p : list){
        newList.append(transformPointToQPoint(p));
    }

    return newList;
}
QPoint Point::transformPointToQPoint(Point p)
{
    return QPoint(p.x,p.y);
}
