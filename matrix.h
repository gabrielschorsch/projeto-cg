
#ifndef MATRIX_H
#define MATRIX_H


#include <QObject>
#include <QPoint>
#include <QList>


class Matrix : QObject
{
    Q_OBJECT
private:
public:
    QList<QPoint> points;
    Matrix ();
    Matrix(QList<QPoint> *mPoints);
    void appendPoint(int x, int y);
    void translate( float dx, float dy);
    void scale(float sx, float sy);
    void rotate(float angle);

};

#endif // MATRIX_H
