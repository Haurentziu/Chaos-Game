#ifndef ROTATIONAL_TRANSFORMATION_H
    #define ROTATIONAL_TRANSFORMATION_H
    #include "transformation.h"
    class RotationalTransformation : public Transformation{
        public:
            RotationalTransformation(double, double, double, double, double, double);
            RotationalTransformation();
    };

#endif
