#include "clipping.h"

Clipping::Clipping(QList<QPoint> windowPoints)
{
    this->windowPoints = windowPoints;
}


void Clipping::setRegionCode(QPoint point, int regionCode[4]){
    if(point.y() > this->windowPoints[1].y()) {
        regionCode[0] = 1;
    } else {
        regionCode[0] = 0;
    }
    //Bottom
    if(point.y() < this->windowPoints[0].y()) {
        regionCode[1] = 1;
    } else {
        regionCode[1] = 0;
    }
    //Right
    if(point.x() > this->windowPoints[1].x()) {
        regionCode[2] = 1;
    } else {
        regionCode[2] = 0;
    }
    //Left
    if(point.x() < this->windowPoints[0].x()) {
        regionCode[3] = 1;
    } else {
        regionCode[3] = 0;
    }
}

QLine Clipping::createClippedLine(QLine line, int regionCodeP1[], int regionCodeP2[]){
    if(regionCodeP1[0] == 0 && regionCodeP1[1] == 0 && regionCodeP1[2] == 0 && regionCodeP1[3] == 0){
        if(regionCodeP2[0] == 1) {
            line = this->topLineEquation(line);
        }
        if(regionCodeP2[1] == 1) {
            line = this->bottomLineEquation(line);
        }
        if(regionCodeP2[2] == 1) {
            line = this->rightLineEquation(line);
        }
        if(regionCodeP2[3] == 1) {
            line = this->leftLineEquation(line);
        }
        return line;
    }

    if(regionCodeP2[0] == 0 && regionCodeP2[1] == 0 && regionCodeP2[2] == 0 && regionCodeP2[3] == 0){
        if(regionCodeP1[0] == 1) {
            line = this->topLineEquation(line);
        }
        if(regionCodeP1[1] == 1) {
            line = this->bottomLineEquation(line);
        }
        if(regionCodeP1[2] == 1) {
            line = this->rightLineEquation(line);
        }
        if(regionCodeP1[3] == 1) {
            line = this->leftLineEquation(line);
        }
        return line;
    }
    Line emptyLine;
    return emptyLine;
}

QLine Clipping::leftLineEquation(QLine line){
    float m;
    m = (float)(line.y2() - line.y1()) / (line.x2() - line.x1());
    if(line.x1() > line.x2()){
        line.setP2(QPoint(this->windowPoints[0].x(),(m * (this->windowPoints[0].x() - line.x1()) + line.y1())));

        return line;
    }
    line.setP1(QPoint(this->windowPoints[0].x(),(m * (this->windowPoints[0].x() - line.x1())) + line.y1()));

    return line;
}

QLine Clipping::rightLineEquation(QLine line){
    float m;
    m = (float)(line.y2() - line.y1()) / (line.x2() - line.x1());
    if(line.x1() > line.x2()){
        line.setP1(QPoint(this->windowPoints[1].x(),m * (this->windowPoints[1].x() - line.x1()) + line.y1()));

        return line;
    }
    line.setP2(QPoint(this->windowPoints[1].x(), (m * (this->windowPoints[1].x() - line.x1()) + line.y1())));
    return line;
}

QLine Clipping::topLineEquation(QLine line) {
    float m;
    m = (float)(line.y2() - line.y1()) / (line.x2() - line.x1());

    if(line.y1() > line.y2()){
        line.setP1(QPoint((line.x1()) + (this->windowPoints[1].y() - line.y1()) / m,this->windowPoints[1].y()));
        return line;
    }
    line.setP2(QPoint((line.x1()) + (this->windowPoints[1].y() - line.y1()) / m,this->windowPoints[1].y() ));

    return line;
}

QLine Clipping::bottomLineEquation(QLine line) {
    float m;
    m = (float)(line.y2() - line.y1()) / (line.x2() - line.x1());
    if(line.y1() > line.y2()){
        line.setP2(QPoint((line.x1()) + (this->windowPoints[0].y() - line.y1()) / m, this->windowPoints[0].y()));
        return line;
    }
    line.setP1(QPoint(line.x1() + (this->windowPoints[0].y() - line.y1()) / m , this->windowPoints[0].y()));

    return line;
}

QList<QLine*> Clipping::clip(QList<QLine*> lines){
    QList<QLine*> newList;

    for(QLine *linePointer : lines) {
        QLine line = *linePointer;
        int regionCodeP1[4], regionCodeP2[4];
        this->setRegionCode(QPoint(line.x1(), line.y1()), regionCodeP1);
        this->setRegionCode(QPoint(line.x2(), line.y2()), regionCodeP2);
        QLine newLine = this->createClippedLine(line, regionCodeP1, regionCodeP2);

        newList.append(&newLine);
    }

    return newList;
}
