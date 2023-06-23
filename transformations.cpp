#include "transformations.h"

transformations::transformations()
{

}

QList<QPoint> transformations::rotate(QList<QPoint> points, float rotationAngle){

}

QList<QPoint> transformations::scale(QList<QPoint> points, float sx, float sy){
    float result[3][1];
    float s[3][3];
    float p[3][1];

    QList<QPoint> resultList;


    result[0][0] = 0;
    result[1][0] = 0;
    result[2][0] = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == i){
                switch(i){
                case 0:
                    s[i][j] = sx;
                    break;
                case 1:
                    s[i][j] = sy;
                    break;
                default:
                    s[i][j] = 1;
                }
            } else {
                s[i][j] = 0;
            }
        }
    }
    QList<QPoint> originPoints = this->translate(points, -points.at(0).x(),-points.at(0).y());

    for(QPoint p1 : originPoints){
        p[0][0] = p1.x();
        p[1][0] = p1.y();
        p[2][0] = 1;

        for(int i=0; i<3; i++){
            float sum = 0;
            for(int j=0; j<3; j++){
                sum += s[i][j] * p[j][0];
            }
            result[i][0] = sum;
        }
        QPoint translatedPoint(result[0][0], result[1][0]);
        resultList.append(translatedPoint);
    }

    QList<QPoint> retranslatedPoints = this->translate(resultList,points.at(0).x(),points.at(0).y());
    return retranslatedPoints;
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
