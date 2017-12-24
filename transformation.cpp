#include "transformation.h"
#include <iostream>

#define DIMENSION 2

Transformation::Transformation(){
    double identityMatrix[2][2] = {{1.0, 0.0},{0.0, 1.0}};
    double nullMatrix[] = {0, 0};
    this->setMultiplicationMatrix(identityMatrix);
    this->setAddMatrix(nullMatrix);
    this->setProbability(1.0);
}

Transformation::Transformation(double mMatrix[DIMENSION][DIMENSION], double aMatrix[DIMENSION], double prob){
    this->setMultiplicationMatrix(mMatrix);
    this->setAddMatrix(aMatrix);
    this->setProbability(prob);
}


Point Transformation::apply(Point p){
    double x = multiplicationMatrix[0][0] * p.getX() + multiplicationMatrix[0][1] * p.getY() + addMatrix[0];
    double y = multiplicationMatrix[1][0] * p.getX() + multiplicationMatrix[1][1] * p.getY() + addMatrix[1];
    Point newPoint(x, y);
    return newPoint;
}

void Transformation::setMultiplicationMatrix(double matrix[DIMENSION][DIMENSION]){
    for(int i = 0; i < DIMENSION; i++)
        for(int j = 0; j < DIMENSION; j++)
            multiplicationMatrix[i][j] = matrix[i][j];
}

void Transformation::setAddMatrix(double matrix[2]){
    for(int i = 0; i < DIMENSION; i++)
        addMatrix[i] = matrix[i];
}

void Transformation::setProbability(double p){
    this->probability = p;
}

double* Transformation::getAddMatrix(){
    return addMatrix;
}

double* Transformation::getMultiplicationMatrix(){
    return *multiplicationMatrix;
}

double Transformation::getProbability(){
    return probability;
}
