#include "transformation.h"
#include "system.h"
#include <stdlib.h>

#include <iostream>
System::System(int n, Transformation* transforms){
    transformations = new Transformation[number];
    transformations = transforms;
    number = n;
}

System::System(){
    transformations = 0;
    number = 0;
}


Point System::applyNextTransform(Point p){
    double random = (double)rand() / RAND_MAX;
    int selectedTransform = 0;
    for(int i = 0; i < number; i++){
        random -= transformations[i].getProbability();
        if(random <= 0){
            selectedTransform = i;
            break;
        }
    }
    return transformations[selectedTransform].apply(p);
}
