
#ifndef MATRIX_H
#define MATRIX_H


#include <QObject>
#include <QPoint>
#include <QList>
#include <QPen>


class Matrix
{
public:
    float matrix[3][3];
    Matrix();
    Matrix translate( float dx, float dy);
    Matrix translate( float dx, float dy, float dz);
    Matrix scale(float sx, float sy);
    Matrix scale(float sx, float sy, float sz);
    Matrix rotate(float angle);
    Matrix rotate(float angle, int axis);
    Matrix operator*(const Matrix& other) const;

};

#endif // MATRIX_H
