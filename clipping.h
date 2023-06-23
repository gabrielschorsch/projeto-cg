#ifndef CLIPPING_H
#define CLIPPING_H
#include <QList>
#include <QPoint>
#include "window.h"
#include "point.h"
#include "line.h"

class Clipping
{
private:
    QList<QPoint> windowPoints;
public:
    Clipping(QList<QPoint> windowPoints);
    void setRegionCode(QPoint point, int regionCode[4]);
    QLine createClippedLine(QLine line, int regionCodeP1[4], int regionCodeP2[4]);
    QLine leftLineEquation(QLine line);
    QLine rightLineEquation(QLine line);
    QLine topLineEquation(QLine line);
    QLine bottomLineEquation(QLine line);
    QList<QLine*> clip(QList<QLine*> lines);
};

#endif // CLIPPING_H
