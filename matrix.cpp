
#include "matrix.h"
#include "iostream"
#include <cmath>
#define PI 3.14159

using namespace std;


Matrix::Matrix(){
    this->matrix[0][0] = 1;
    this->matrix[1][0] = 0;
    this->matrix[2][0] = 0;
    this->matrix[0][1] = 0;
    this->matrix[1][1] = 1;
    this->matrix[2][1] = 0;
    this->matrix[0][2] = 0;
    this->matrix[1][2] = 0;
    this->matrix[2][2] = 1;
}


Matrix Matrix::scale(float sx, float sy){
    Matrix m;
    m.matrix[0][0] = sx;
    m.matrix[1][1] = sy;

    m = m * (*this);

    return m;
}


Matrix Matrix::translate(float dx, float dy){
    Matrix m;
    m.matrix[0][2] = dx;
    m.matrix[1][2] = dy;

    m = m * (*this);

    return m;
}

Matrix Matrix::rotate(float angle){

    Matrix m;
    cout << "rotating" << endl;
    m.matrix[0][0] = cos(angle*(PI/180));
    m.matrix[1][0] = sin(angle*(PI/180));
    m.matrix[0][1] = -sin(angle*(PI/180));
    m.matrix[1][1] = cos(angle*(PI/180));

    return m;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix m;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m.matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                m.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return m;
}
