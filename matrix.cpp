
#include "matrix.h"
#include "iostream"
#include <cmath>

using namespace std;


Matrix::Matrix(){
}


Matrix::Matrix(QList<QPoint> *mPoints){
    this->points = *mPoints;
}

void Matrix::scale(float sx, float sy){

    //translate center point to origin
    int minX=312321321,
        minY=312321321,
        maxX=0,
        maxY=0;



    //find min and max points
    for(int i = 0; i < this->points.length();i++){

        if(this->points[i].x() < minX){
            minX = this->points[i].x();
        }
        if(this->points[i].x() > maxX){
            maxX =this->points[i].x();
        }

        if(this->points[i].y() < minY){
            minY = this->points[i].y();
        }
        if(this->points[i].y() > maxY){
            maxY =this->points[i].y();
        }

    }

    int centerX = (minX + maxX )/2,
        centerY = (minY + maxY )/2;


    this->translate(-centerX, -centerY);
    for(int i = 0; i < this->points.length(); i++){
        //for each point, multiply its coordinates by sx and sy
    this->points[i].setX(
        (this->points[i].x() * sx)
        );

    this->points[i].setY(
        (this->points[i].y() * sy)
        );
    }
    //translate back to place
    this->translate(centerX, centerY);
}

void Matrix::appendPoint(int x, int y){
    this->points.append(QPoint(x,y));
}

void Matrix::translate(float dx, float dy){
    QList<QPoint> newList = this->points;
    for(int i = 0; i < newList.length(); i++){
        newList[i].setX(newList[i].x() + dx);
        newList[i].setY(newList[i].y() + dy);
    }
    this->points = newList;
}

void Matrix::rotate(float angle){


    int minX=this->points[0].x(),
        minY=this->points[0].y(),
        maxX=this->points[0].x(),
        maxY=this->points[0].y();





    //find min and max points
    for(int i = 0; i < this->points.length();i++){

        if(this->points[i].x() < minX){
            minX = this->points[i].x();
        }
        if(this->points[i].x() > maxX){
            maxX =this->points[i].x();
        }

        if(this->points[i].y() < minY){
            minY = this->points[i].y();
        }
        if(this->points[i].y() > maxY){
            maxY =this->points[i].y();
        }

    }


    int pivotX = (minX + maxX )/ 2, pivotY = (minY + maxY )/ 2;

    //translate to origin
    this->translate(-pivotX, -pivotY);
    for(int i = 0; i < this->points.length(); i++){
        int x = this->points[i].x();
        int y = this->points[i].y();
        this->points[i].setX(
            x*cos(angle) - y*sin(angle)
            );

        cout <<"point rotated from " << this->points[i].x() << "," << this->points[i].y();
        this->points[i].setY(
            x*sin(angle) + y*cos(angle)
            );



        cout <<" to " << this->points[i].x() << "," << this->points[i].y() << endl;
    }
    //translate back to place
    this->translate(pivotX, pivotY);

}
