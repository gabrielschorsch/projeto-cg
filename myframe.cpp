#include "myframe.h"
#include "iostream"

using namespace std;

int inicio = 0, fim = 0;

MyFrame::MyFrame(QWidget *w): QFrame(w)
{
}

void MyFrame::paintEvent(QPaintEvent *event){
    QFrame::paintEvent(event);
    QPainter pen(this);
    pen.setPen(QPen(Qt::blue,2));

    pen.drawLine(inicio,inicio,inicio,fim);
    pen.drawLine(inicio,inicio,fim,inicio);
    pen.drawLine(fim,inicio,fim,fim);
    pen.drawLine(inicio,fim,fim,fim);
}

void MyFrame::draw(){
    inicio += 5;
    fim += 10;
    update();
}
