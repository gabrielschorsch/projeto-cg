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

using namespace std;


int VIEWPORT_X_MIN = 500;
int VIEWPORT_X_MAX = VIEWPORT_X_MIN + 500;
int VIEWPORT_Y_MIN = 50;
int VIEWPORT_Y_MAX = VIEWPORT_Y_MIN + 500;


int WINDOW_X_MIN = 200;
int WINDOW_X_MAX = 800;
int WINDOW_Y_MIN = 0;
int WINDOW_Y_MAX = 800;


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
    pen.setWidth(2);
    painter.setPen(pen);


    QList<Object *> displayFile;

    QPoint vp1(VIEWPORT_X_MIN, VIEWPORT_Y_MIN);
    QPoint vp2(VIEWPORT_X_MIN, VIEWPORT_Y_MAX);
    QPoint vp3(VIEWPORT_X_MAX, VIEWPORT_Y_MIN);
    QPoint vp4(VIEWPORT_X_MAX, VIEWPORT_Y_MAX);

    Window window(VIEWPORT_X_MIN, VIEWPORT_X_MAX, VIEWPORT_Y_MIN, VIEWPORT_Y_MAX, WINDOW_X_MIN,WINDOW_X_MAX,WINDOW_Y_MIN,WINDOW_Y_MAX);

    cout << window.getViewportX(0) << endl;
    cout << window.getViewportY(0) << endl;

    QList<QPoint> points = {QPoint(0,0), QPoint(0, -100),QPoint(100,0), QPoint(100, -100) };
    transformations t;
    QList<QPoint> pointss= t.translate(points,200,200);
    Rect vp(pointss);
    QList<QPoint> scaled = t.scale(pointss,.5,.5);
    Rect scaledRect(scaled);
    QList<QPoint> rotated = t.rotate(pointss, 45);
    Rect rotatedRect(rotated);
    vp.draw(&painter);
    scaledRect.draw(&painter);
    rotatedRect.draw(&painter);



//    cout << "Scale scale" << endl;
//    for(QPoint p : scaledPoints){
//        cout << p.x() << "," << p.y() << endl;
//    }

//    Rect viewport(viewportPoints);

//    viewport.draw(&painter);

//    QPen pen2;
//    pen2.setColor(Qt::blue);
//    pen2.setWidth(0);
//    pen2.setColor(Qt::red);
//    painter.setPen(pen2);
//    QList<QPoint> rotated = t.rotate(scaledPoints, 45);
//    Rect scaled(rotated);

//    scaled.draw(&painter);


}

MainWindow::~MainWindow()
{
    delete ui;
}

