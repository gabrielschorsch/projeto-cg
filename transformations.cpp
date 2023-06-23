#include "transformations.h"

transformations::transformations()
{

}

QList<QPoint> transformations::rotate(QList<QPoint> points, float rotationAngle){

}

QList<QPoint> transformations::scale(QList<QPoint> points, float sX, float sY){

}

QList<QPoint> transformations::translate(QList<QPoint> points, float dx, float dy){
    float result[3][1];
    float t[3][3];
    float p[3][3];

    QList<QPoint> newPoints;

    //remove memory dump
    result[0][0] = 0;
    result[1][0] = 0;
    result[2][0] = 0;

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            if(i==j){
                t[i][j] = 1;
            } else {
                t[i][j] = 0;
            }
        }
    }
    t[0][2] = dx;
    t[1][2] = dy;

    for(QPoint point : points){
        p[0][0] = point.x();
        p[1][0] = point.y();
        p[2][0] = 1;

        for(int i = 0; i < 3; i++){
            float sum = 0;
            for(int j = 0; j < 3; j++){
                sum += t[i][j] * p[j][0];
            }
            result[i][0] = sum;
        }
        newPoints.append(QPoint(result[0][0], result[1][0]));
    }

    return newPoints;

}
