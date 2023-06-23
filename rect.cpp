#include "rect.h"
#include "iostream"

using namespace std;
Rect::Rect(int x,int y, int w, int h)
{
    cout << "building rect" << endl;
    QPoint p1(x,y);
    QPoint p2(x + w , y);
    QPoint p3(x, y + h);
    QPoint p4(x+w, y+h);
    this->points.append(p1);
    this->points.append(p2);
    this->points.append(p3);
    this->points.append(p4);
    cout << this->points.length() << endl;
}

Rect::Rect(QList<QPoint> points)
{
    cout << "building rect with list" << endl;
    this->points.append((points.at(0)));
    this->points.append((points.at(1)));
    this->points.append((points.at(2)));
    this->points.append((points.at(3)));
}




void Rect::draw(QPainter* pen){
    cout << this->points.length() << endl;
    pen->drawLine((this->points.at(0)), (this->points.at(1)));
    pen->drawLine((this->points.at(0)), (this->points.at(2)));
    pen->drawLine((this->points.at(1)), (this->points.at(3)));
    pen->drawLine((this->points.at(2)), (this->points.at(3)));
}
