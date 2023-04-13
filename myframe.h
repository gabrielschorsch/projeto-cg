#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QFrame>
#include <QPoint>


class MyFrame : public QFrame
{
    Q_OBJECT
public:
    MyFrame(QWidget *w);
    void paintEvent(QPaintEvent *e);
public slots:
    void draw();
    void scaleObject();
    void rotateObject();
    void moveWindow(int x, int y);

    void moveWindowLeft();
    void moveWindowRight();
};

#endif // MYFRAME_H
