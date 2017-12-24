#ifndef TRANSFORMATION_H
    #define TRANSFORMATION_H
    #include "point.h"
    class Transformation{

        private:
          double probability;
          double multiplicationMatrix[2][2];
          double addMatrix[2];

        public:
            Transformation(double[2][2], double[2], double);
            Transformation();
            double getProbability();
            void setProbability(double);
            double* getMultiplicationMatrix();
            void setMultiplicationMatrix(double[2][2]);
            double* getAddMatrix();
            void setAddMatrix(double[2]);

            Point apply(Point);


    };
#endif // TRANSFORMATION_H
