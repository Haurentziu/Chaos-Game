#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "transformation.h"
#include "rotationalTransformation.h"
#include "system.h"
#include <math.h>
#include <iomanip>

using namespace std;

#define COS_THETA 0.46
#define SIN_THETA 0.46

Transformation FERN[] = {
    Transformation((double[2][2]){{0, 0}, {0, 0.16}}, (double[]){0, 0.01}, 0.01),
    Transformation((double[2][2]){{0.85, 0.04}, {-0.04, 0.85}}, (double[]){0, 1.60}, 0.85),
    Transformation((double[2][2]){{0.20, -0.26}, {0.23, 0.22}}, (double[]){0, 1.60}, 0.07),
    Transformation((double[2][2]){{-0.15, 0.28}, {0.26, 0.24}}, (double[]){0, 0.44}, 0.07),
};

Transformation SIERPINSKI_TRIANGLE[] = {
    Transformation((double[2][2]){{0.5, 0}, {0, 0.5}}, (double[]){0, 0.0}, 0.2),
    Transformation((double[2][2]){{0.5, 0.0}, {0, 0.5}}, (double[]){0.5, 0}, 0.2),
    Transformation((double[2][2]){{0.5, 0}, {0, 0.5}}, (double[]){0.25, 0.5}, 0.2),
    Transformation((double[2][2]){{0.5, 0}, {0, 0.5}}, (double[]){0.5, 0.0}, 0.2),
    Transformation((double[2][2]){{0.5, 0}, {0, 0.5}}, (double[]){0.25, 0.5}, 0.2),
};

Transformation KOCH_CURVE[] = {
    Transformation((double[2][2]){{0.33, 0}, {0, 0.33}}, (double[]){0, 0.0}, 0.25),
    Transformation((double[2][2]){{0.17, -0.29}, {0.29, 0.17}}, (double[]){0.33, 0}, 0.25),
    Transformation((double[2][2]){{0.17, 0.29}, {-0.29, 0.17}}, (double[]){0.5, 0.29}, 0.25),
    Transformation((double[2][2]){{0.33, 0}, {0, 0.33}}, (double[]){0.67, 0.0}, 0.25),
};


Transformation TREE[] = {
    Transformation((double[2][2]){{COS_THETA, -SIN_THETA}, {SIN_THETA, COS_THETA}}, (double[]){0.0, 1.0}, 0.5),
    Transformation((double[2][2]){{COS_THETA, SIN_THETA}, {-SIN_THETA, COS_THETA}}, (double[]){1.0, 0.0}, 0.5),
   // Transformation((double[2][2]){{1.0, 0}, {0, 1.0}}, (double[]){0, 0}, 0.34),
};

Transformation CANTOR_MAZE[] = {
    Transformation((double[2][2]){{0.333, 0.000}, {0.000, 0.333}}, (double[]){0.333, 0.667}, 0.2),
    Transformation((double[2][2]){{0.000, -0.333}, {1.0, 0}}, (double[]){0.333, 0.0}, 0.4),
    Transformation((double[2][2]){{0.000, 0.333}, {1.000, 0.0}}, (double[]){0.667, 0}, 0.4),
};


Transformation CHRISTMAS[] = {
    Transformation((double[2][2]){{0.0, -0.5}, {0.5, 0.0}}, (double[]){0.5, 0.0}, 0.34),
    Transformation((double[2][2]){{0.0, 0.5}, {-0.5, 0.0}}, (double[]){0.5, 0.5}, 0.33),
    Transformation((double[2][2]){{0.5, 0.0}, {0.0, 0.5}}, (double[]){0.25, 0.5}, 0.33),
};

Transformation TREE1[] = {
    Transformation((double[2][2]){{0.195, -0.488}, {0.344, 0.443}}, (double[]){0.4431, 0.2452}, 0.30),
    Transformation((double[2][2]){{0.462, 0.414}, {-0.252, 0.361}}, (double[]){0.2511, 0.5692}, 0.30),
    Transformation((double[2][2]){{-0.058, -0.07}, {0.453, -0.111}}, (double[]){0.5976, 0.0969}, 0.05),
    Transformation((double[2][2]){{-0.035, 0.07}, {-0.469, 0.022}}, (double[]){0.4884, 0.5069}, 0.05),
    Transformation((double[2][2]){{-0.637, 0.0}, {0.0, 0.501}}, (double[]){0.8662, 0.2513}, 0.30),

};

Transformation TREE2[] = {
    Transformation((double[2][2]){{0.01, 0}, {0.00, 0.45}}, (double[]){0.0, 0.0}, 0.15),
    Transformation((double[2][2]){{-0.01, 0.0}, {0.0, -0.45}}, (double[]){0, 0.4}, 0.05),
    Transformation((double[2][2]){{0.42, -0.42}, {0.42, 0.42}}, (double[]){0.0, 0.42}, 0.4),
    Transformation((double[2][2]){{0.42, 0.42}, {-0.42, 0.42}}, (double[]){0.0, 0.4}, 0.4),

};

void render(Transformation* trans, int n){
    ofstream outfile;
    outfile.open("./points.dat");

    Point p(0.0, 0.0);
    System s = System(sizeof(trans), trans);

    for(int i = 0; i < n; i++){
        p = s.applyNextTransform(p);
        outfile<<p.getX()<<"\t"<<p.getY()<<endl;
        if(i%100 == 0){
            cout<<"\r";
            cout<<(int)(10000.0 * i / n) / 100.0<<"%";
        }

    }
    cout<<"\r";
    cout<<"Done!"<<endl<<endl;
    outfile.close();
}

Transformation* askRotational(){
    cout<<endl;
    int n;
    cout<<"Number of transformations: ";
    cin>>n;
    RotationalTransformation trans[n];
    double angle, tx, ty, prob, sx, sy;
    for(int i = 0; i < n; i++){
        cout<<"Angle(deg): ";
        cin>>angle;

        cout<<"x scale: ";
        cin>>sx;

        cout<<"y scale: ";
        cin>>sy;

        cout<<"x translation: ";
        cin>>tx;

        cout<<"y translation: ";
        cin>>ty;

        cout<<"probability(%)";
        cin>>prob;
        cout<<endl;
        trans[i] = RotationalTransformation(M_PI * angle / 180.0, sx, sy, tx, ty, prob / 100.0);
    }
    return trans;
}

void askForChoice(){
    cout<<"Choose fractal: "<<endl;
    cout<<"  "<<"1. Barnsley Fern"<<endl;
    cout<<"  "<<"2. Sierpinski Triangle"<<endl;
    cout<<"  "<<"3. Koch Curve"<<endl;
    cout<<"  "<<"4. Pythagoras Tree"<<endl;
    cout<<"  "<<"5. Cantor Maze"<<endl;
    cout<<"  "<<"6. Twin Christmas Tree"<<endl;
    cout<<"  "<<"7. Tree 1"<<endl;
    cout<<"  "<<"8. Tree 2"<<endl;
    cout<<"  "<<"9. Rotational Transformation"<<endl<<endl;
    cout<<"  "<<"10. EXIT PROGRAM"<<endl<<endl;
    cout<<"Your choice: ";
    int choice;
    cin>>choice;

    if(choice == 10)
        exit(0);

    int n;

    cout<<endl;
    int numberChoice;
    cout<<"Select number of points: "<<endl;
    cout<<"  "<<"1. 100,000"<<endl;
    cout<<"  "<<"2. 500,000"<<endl;
    cout<<"  "<<"3. 1,000,000"<<endl;
    cout<<"  "<<"4. Custom"<<endl<<endl;
    cout<<"Your choice: ";
    cin>>numberChoice;

    if(numberChoice == 1){
        n = 1e5;
    }
    else if(numberChoice == 2){
        n = 5e5;
    }
    else if(numberChoice == 3){
        n = 1e6;
    }
    else if(numberChoice == 4){
        cout<<"Number of points: ";
        cin>>n;
    }

    if(choice == 1){
        render(FERN, n);
    }
    else if(choice == 2){
        render(SIERPINSKI_TRIANGLE, n);
    }
    else if(choice == 3){
        render(KOCH_CURVE, n);
    }
    else if(choice == 4){
        render(TREE, n);
    }
    else if(choice == 5){
        render(CANTOR_MAZE, n);
    }
    else if(choice == 6){
        render(CHRISTMAS, n);
    }
    else if(choice == 7){
        render(TREE1, n);
    }
    else if(choice == 8){
        render(TREE2, n);
    }

    else if(choice == 9){
        Transformation* trans = askRotational();
        render(trans, sizeof(trans));
    }

}

int main(){
    cout<<"Iterated Function System"<<endl;
    while(true)
        askForChoice();
    return 0;
}
