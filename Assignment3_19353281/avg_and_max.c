//
// Created by Yiming Zhao on 2020/5/13.
//

#include "avg_and_max.h"

double average(double array[], int size){
    double sum = 0;
    for(int i =0; i < size - 1; i++){//i < size - 1 should be changed to i < size or i <= size-1
        sum += array[i];
    }
    return sum/size;

}

double max (double array[], int size){
    double max;//max is not initialized properly
    for(int i =0; i < size ; i++){
        if(max < array[i])
            max = array[i];
    }
    return max;

}

