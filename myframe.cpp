#include "myframe.h"
#include "iostream"
#include "matrix.h"

using namespace std;

Matrix m;

MyFrame::MyFrame(QWidget *w): QFrame(w)
{

}


void MyFrame::paintEvent(QPaintEvent *event){


    QFrame::paintEvent(event);
    QPainter pen(this);
    pen.setPen(QPen(Qt::blue,2));

    for(int i =0; i < m.points.length(); i+=2){
        pen.drawLine(m.points[i].x(),m.points[i].y(), m.points[i+1].x(), m.points[i+1].y());
    }
}

void MyFrame::draw(){
    m.appendPoint(10,10);
    m.appendPoint(10,20);
    m.appendPoint(10,20);
    m.appendPoint(20,20);
    m.appendPoint(20,20);
    m.appendPoint(20,10);
    m.appendPoint(20,10);
    m.appendPoint(10,10);
    update();
}


void MyFrame::rotateObject(){
    m.rotate(45);
    update();
}

void MyFrame::scaleObject(){
    m.scale(1.5,1.5);
    update();
}
