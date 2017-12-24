#ifndef POINT_H
    #define POINT_H
    class Point{
        private:
            double x;
            double y;

        public:
            double getX();
            double getY();
            void setX(double);
            void setY(double);

            Point(double, double);

    };
#endif
