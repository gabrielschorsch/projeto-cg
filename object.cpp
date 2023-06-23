#include "object.h"
#include "iostream"

using namespace std;

Object::Object()
{

}

Point Object::getObjectCenterPoint(){
    int size = this->points.length();
    float xSum = 0;
    float ySum = 0;
    for(Point *p : this->points){
        xSum += (*p).x;
        ySum += (*p).y;
    }
    return Point((xSum/size), (ySum/size));
}

void Object::translate(float dx, float dy){
//    QList<Point> newPoints;

}

void Object::draw(QPainter *pen){

}
