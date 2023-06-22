#include "myframe.h"
#include "iostream"
#include "matrix.h"
#include "window.h"
#include <QList>

using namespace std;


QList<Matrix> displayFile;

int VIEWPORT_X_MIN = 250;
int VIEWPORT_X_MAX = VIEWPORT_X_MIN + 500;
int VIEWPORT_Y_MIN = 10;
int VIEWPORT_Y_MAX = VIEWPORT_Y_MIN + 500;


int WINDOW_X_MIN = 0;
int WINDOW_X_MAX = 800;
int WINDOW_Y_MIN = 0;
int WINDOW_Y_MAX = 800;




MyFrame::MyFrame(QWidget *w): QFrame(w)
{

}


void MyFrame::paintEvent(QPaintEvent *event){

    QList<QPoint> normalizedPoints;
    QFrame::paintEvent(event);
    QPainter pen(this);
    Window w;
    pen.setPen(QPen(Qt::blue,2));
    for(Matrix m : displayFile){
        for(QPoint p : m->points) {
            normalizedPoints.append(w.convertToViewport(p.x(),p.y(),WINDOW_X_MAX,WINDOW_Y_MAX,WINDOW_X_MIN,WINDOW_Y_MIN,VIEWPORT_X_MAX, VIEWPORT_Y_MAX, VIEWPORT_X_MIN, VIEWPORT_Y_MIN));
        }
    }


    for(int i =0; i < normalizedPoints.length(); i+=2){
        pen.drawLine(normalizedPoints[i].x(),normalizedPoints[i].y(), normalizedPoints[i+1].x(), normalizedPoints[i+1].y());
    }
}

void MyFrame::draw(){
    Matrix m;

    m.appendPoint(10,10);
    m.appendPoint(10,20);
    m.appendPoint(10,20);
    m.appendPoint(20,20);
    m.appendPoint(20,20);
    m.appendPoint(20,10);
    m.appendPoint(20,10);
    m.appendPoint(10,10);

    displayFile.append(m);
    update();
}


void MyFrame::rotateObject(){
    m.rotate(45);
    update();
}

void MyFrame::scaleObject(){
    update();
}

void MyFrame::moveWindow(int x, int y){
    WINDOW_X_MIN += x;
    WINDOW_X_MAX += x;
    WINDOW_Y_MIN += y;
    WINDOW_Y_MAX += y;
    update();
}


void MyFrame::moveWindowLeft(){
    moveWindow(50,0);
}

void MyFrame::moveWindowRight(){
    moveWindow(-50,0);
}
