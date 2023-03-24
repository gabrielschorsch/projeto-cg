#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QFrame>
#include <QRect>
#include <QPoint>

class MyFrame : public QFrame
{
    Q_OBJECT
public:
    QRect rect;
    MyFrame(QWidget *w);
    void paintEvent(QPaintEvent *e);
public slots:
     void draw();

};

#endif // MYFRAME_H
