#include "myframe.h"
#include "iostream"
#include "matrix.h"
#include "window.h"
#include <QList>
#include "rect.h"

using namespace std;





MyFrame::MyFrame(QWidget *w): QFrame(w)
{

}

Rect r = Rect(10,10,50,20);

void MyFrame::paintEvent(QPaintEvent *event){

    QList<QPoint> normalizedPoints;
    QFrame::paintEvent(event);
    QPainter pen(this);
    pen.setPen(QPen(Qt::blue,2));

    if(!displayFile.contains(&r)){
        displayFile.append(&r);
    }

    displayFile.at(0)->draw(&pen);

//    for(Object m : displayFile){
//        for(QPoint p : m->points) {
//            normalizedPoints.append(w.convertToViewport(p.x(),p.y(),WINDOW_X_MAX,WINDOW_Y_MAX,WINDOW_X_MIN,WINDOW_Y_MIN,VIEWPORT_X_MAX, VIEWPORT_Y_MAX, VIEWPORT_X_MIN, VIEWPORT_Y_MIN));
//        }
//    }

//    for(int i =0; i < normalizedPoints.length(); i+=2){
//        pen.drawLine(normalizedPoints[i].x(),normalizedPoints[i].y(), normalizedPoints[i+1].x(), normalizedPoints[i+1].y());
//    }
}

void MyFrame::draw(){
    update();
}


void MyFrame::rotateObject(){
    Object* obj = displayFile.at(0);

    update();
}

void MyFrame::scaleObject(){
    update();
}

//void MyFrame::moveWindow(int x, int y){
//    WINDOW_X_MIN += x;
//    WINDOW_X_MAX += x;
//    WINDOW_Y_MIN += y;
//    WINDOW_Y_MAX += y;
//    update();
//}

