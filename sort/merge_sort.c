#include <stdio.h>
#include "sort.h"

void merge(int* ary, int low, int middle, int high){

    int i = low;
    int j = middle + 1;
    int k = low;

    while( i <= middle && j <= high){

        if(ary[i] <= ary[j]){
            sorted[k] = ary[i];
            i++;
        }else {
            sorted[k] = ary[j];
            j++;
        }
        k++;
    }
    
    /* Insert rest data in sorted array */
    if( i >  middle){
        for( int t = j ; t <= middle ; t++ ){
            sorted[k] = ary[t];
            k++;
        }
    }else {
        for( int t = i ; t<= middle ; t++){
            sorted[k] = ary[t];
            k++;
        }
    }

    /* Insert sorted array into 'origin' array */
    for( int t = low ; t <= high ; t++){
        ary[t] = sorted[t];
    }

}


void merge_sort(int *ary, int low, int high){

    int middle;

    if( low<high ){
        middle = ( low+high )/2;

        merge_sort(ary, low, middle); // 
        merge_sort(ary, middle+1, high);
        merge(ary, low, middle, high); // merge
    }
}
