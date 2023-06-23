#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "object.h"
#include "qlist.h"
#include "qpen.h"
#include "qpainter.h"
#include "rect.h"
#include "window.h"
#include "transformations.h"
#include "iostream"
#include "clipping.h"

using namespace std;


int VIEWPORT_X_MIN = 150;
int VIEWPORT_X_MAX = VIEWPORT_X_MIN + 500;
int VIEWPORT_Y_MIN = 10;
int VIEWPORT_Y_MAX = VIEWPORT_Y_MIN + 500;


int WINDOW_X_MIN = 0;
int WINDOW_X_MAX = 800;
int WINDOW_Y_MIN = 0;
int WINDOW_Y_MAX = 800;


QList<QPoint> windowPoints = {QPoint(-200,0), QPoint(200,0)};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(0);
    painter.setPen(pen);


    QList<Object *> displayFile;

    QPoint vp1(VIEWPORT_X_MIN, VIEWPORT_Y_MIN);
    QPoint vp2(VIEWPORT_X_MIN, VIEWPORT_Y_MAX);
    QPoint vp3(VIEWPORT_X_MAX, VIEWPORT_Y_MIN);
    QPoint vp4(VIEWPORT_X_MAX, VIEWPORT_Y_MAX);
    QList<QPoint> viewportPoints = {
            vp1,
            vp2,
            vp3,
            vp4
    };

    transformations t;
    cout << "Viewport points" << endl;
    for(QPoint p : viewportPoints){
        cout << p.x() << "," << p.y() << endl;
    }

    QList<QPoint> scaledPoints = t.scale(viewportPoints,.25,.25);

    cout << "Scale scale" << endl;
    for(QPoint p : scaledPoints){
        cout << p.x() << "," << p.y() << endl;
    }

    Rect viewport(viewportPoints);

    viewport.draw(&painter);

    Window window;
    Clipping clipping(windowPoints);

    QPen pen2;
    pen2.setColor(Qt::blue);
    pen2.setWidth(0);
    pen2.setColor(Qt::red);
    painter.setPen(pen2);
<<<<<<< HEAD
    Rect scaled(scaledPoints);
    QList<QPoint> rotatedPoints = t.rotate(scaledPoints, 45);
    Rect rotated(rotatedPoints);
    displayFile.append(&scaled);
    displayFile.append(&rotated);

    for(Object *obj : displayFile){
//        obj->lines = clipping.clip(obj->lines);
        obj->draw(&painter);

    }
=======

    Rect scaled(scaledPoints);
>>>>>>> parent of 8804100... rotation working





    window.convertToViewport(0,0,WINDOW_X_MAX, WINDOW_Y_MAX, WINDOW_X_MIN, WINDOW_Y_MIN, VIEWPORT_X_MAX, VIEWPORT_Y_MAX, VIEWPORT_X_MIN, VIEWPORT_Y_MIN);

}

MainWindow::~MainWindow()
{
    delete ui;
}

