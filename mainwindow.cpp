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


int VIEWPORT_X_MIN = 250;
int VIEWPORT_X_MAX = VIEWPORT_X_MIN + 500;
int VIEWPORT_Y_MIN = 10;
int VIEWPORT_Y_MAX = VIEWPORT_Y_MIN + 500;


int WINDOW_X_MIN = 0;
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
    QList<QPoint> translatedPoints = t.translate(viewportPoints,100,100);
    cout << "Viewport points:" << endl;
    for(QPoint p : viewportPoints){
        cout <<"Ponto v: " << p.x() << "," << p.y() << endl;
    }
    cout << "Translated points:" << endl;
    for(QPoint p : translatedPoints){
        cout <<"Ponto t: " << p.x() << "," << p.y() << endl;
    }

    Rect viewport(translatedPoints);
    viewport.draw(&painter);


    QPen pen2;
    pen2.setColor(Qt::blue);
    pen2.setWidth(0);
    pen2.setColor(Qt::red);
    painter.setPen(pen2);

    Window window;

    window.convertToViewport(0,0,WINDOW_X_MAX, WINDOW_Y_MAX, WINDOW_X_MIN, WINDOW_Y_MIN, VIEWPORT_X_MAX, VIEWPORT_Y_MAX, VIEWPORT_X_MIN, VIEWPORT_Y_MIN);

}

MainWindow::~MainWindow()
{
    delete ui;
}

