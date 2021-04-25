#include <stdio.h>
#include "sort.h"
void insertion_sort(int* ary, int size){

    int i, j, key;
    //compare with first value
    for(i = 1; i < size ; i++){
        key = ary[i];
        for(j = i-1; j>=0 && ary[j] > key; j--){
            /* shift values */
            ary[j+1] = ary[j];
        }
        /* swap with key */
        ary[j+1]= key;
    }
}

