#include <stdio.h>
#include "sort.h"

void bubble_sort(int *ary, int size){
    int i, j, temp;

    for(i = 0 ; i < size-1; i++){
        for(j = 0 ; j < size-i-1; j++){
            if(ary[j]>ary[j+1]){
                temp = ary[j];
                ary[j] = ary[j+1];
                ary[j+1] = temp;
            }
        }
    }
}

