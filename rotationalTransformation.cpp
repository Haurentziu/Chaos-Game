#include "rotationalTransformation.h"
#include <math.h>
RotationalTransformation :: RotationalTransformation(double angle, double scalex, double scaley, double tx, double ty, double prob){
    double mMatrix[2][2] = {
        {
            scalex * cos(angle), -scaley * sin(angle)
        },

        {
            scalex * sin(angle), scaley * cos(angle)
        }
    };
    double aMatrix[] = {tx, ty};
    this->setMultiplicationMatrix(mMatrix);
    this->setAddMatrix(aMatrix);
    this->setProbability(prob);


}

RotationalTransformation :: RotationalTransformation(){
    double identityMatrix[2][2] = {{1.0, 0.0},{0.0, 1.0}};
    double nullMatrix[] = {0, 0};
    this->setMultiplicationMatrix(identityMatrix);
    this->setAddMatrix(nullMatrix);
    this->setProbability(1.0);
}

