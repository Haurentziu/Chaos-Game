#ifndef SYSTEM_H
    #define SYSTEM_H
    #include "transformation.h"

    class System{
        private:
            Transformation* transformations;
            int number;
        public:
            System();
            System(int, Transformation*);
            Point applyNextTransform(Point);


    };

#endif
