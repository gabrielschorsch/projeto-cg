#include "myframe.h"
#include "iostream"

using namespace std;


MyFrame::MyFrame(QWidget *w): QFrame(w)
{
}

void MyFrame::paintEvent(QPaintEvent *event){


    QFrame::paintEvent(event);
    QPainter bluePen(this);
    bluePen.setPen(QPen(Qt::blue,2));

    bluePen.drawRect(rect);

    QPainter redPen(this);
    redPen.setPen(QPen(Qt::red,2));
   redPen.drawLine(rect.topLeft().x(), rect.topLeft().y(), rect.bottomRight().x(), rect.bottomRight().y());
}


void MyFrame::draw(){
    rect.setCoords(20,20,80,80);

    update();
}
