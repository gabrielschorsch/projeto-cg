#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QFrame>
#include <QPoint>

/*class Polygon{
public:
    Polygon(QWidget *w);
    void setPoints(QWidget *w);
private:
    QWidget *points;
};*/

class Ponto {
public:
    float x;
    float y;

    Ponto(){}
    Ponto(float i, float j){ x=i; y=j; }
    ~Ponto(){}
};

class Quadrado: public QWidget{
public:
    QPoint inicio;
    QPoint fim;
    Quadrado(QPoint i, QPoint f){
        inicio = i;
        fim = f;
    }
    Quadrado(){}

    Quadrado(QPoint i, float altura, float largura):
        inicio(i.x(),i.y()),fim(i.x()+largura,i.y()+altura){}

    void draw(){

    }
};

class MyFrame : public QFrame
{
    Q_OBJECT
public:
    Quadrado quadrado;
    MyFrame(QWidget *w);
    void paintEvent(QPaintEvent *e);
public slots:
    void draw();
};

#endif // MYFRAME_H
