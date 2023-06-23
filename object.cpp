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
    cout << "Teste" << endl;
    for(Point *p : this->points){
        cout << (*p).x << endl;
        cout << (*p).y << endl;
    }
}


//void Object::rotate(int degrees){
//    QList<Point> rotatedPoints;

//    cout << "Rotating " << this->points.length() << " points" << endl;

//    Point centerPoint = this->getObjectCenterPoint();

//    this->translate(-centerPoint.x, -centerPoint.y);


//    for(Point p : this->points){
//        cout << "Matrix original: " << endl;
//        cout << "(" << p.x << "," << p.y <<  ")" << endl;
//        Matrix rotatedMatrix = p.rotate(degrees);
//        cout << "Matrix rotacionada: " << endl;
//        cout << "(" << p.matrix[0][0] << "," << p.matrix[1][1] <<  ")" << endl;
//    }



//}



void Object::draw(QPainter *pen){

}
