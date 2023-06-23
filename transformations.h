#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H
#include <QList>
#include <QPoint>


class transformations
{
public:
    transformations();

    QList<QPoint> translate(QList<QPoint> points, float dX, float dY);
    QList<QPoint> scale(QList<QPoint> points, float sX, float sY);
    QList<QPoint> rotate(QList<QPoint> points, float rotationAngle);
};

#endif // TRANSFORMATIONS_H
