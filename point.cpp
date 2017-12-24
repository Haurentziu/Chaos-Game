#include "point.h"

Point::Point(double x, double y){
    setX(x);
    setY(y);
}

void Point::setX(double x){
    this->x = x;
}

void Point::setY(double y){
    this->y = y;
}

double Point::getX(){
    return this->x;
}

double Point::getY(){
    return this->y;
}
