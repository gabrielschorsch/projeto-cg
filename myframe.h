#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QFrame>
#include <QPoint>
#include <QList>
#include "object.h"


class MyFrame : public QFrame
{
    Q_OBJECT
public:
    MyFrame(QWidget *w);
    void paintEvent(QPaintEvent *e);
    QList<Object*> displayFile;
public slots:
    void draw();
    void scaleObject();
    void rotateObject();
//    void moveWindow(int x, int y);

//    void moveWindowLeft();
//    void moveWindowRight();
};

#endif // MYFRAME_H
