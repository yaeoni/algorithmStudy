#include <stdio.h>
#include "sort.h"

// return pivot's idx
int partition(int* list, int left, int right){

    int low, high, temp;
    int pivot = list[left];

    low = left+1;
    high = right;

    while(low < high){

        while( list[low] < pivot && low <= right ) low++;
        while( list[high] > pivot && high >= left ) high--;

        // swap when crossed
        if(low < high){
            temp = list[high];
			list[high] = list[low];
			list[low] = temp;
        }
    }

    // swap with pivot and return
    temp = list[high];
    list[high] = pivot;
    list[left] = temp;

    return high;
}

void quick_sort(int* list, int left, int right){
    int pivotIndex;

    if(left < right){
        pivotIndex = partition(list, left, right);

        quick_sort(list, left, pivotIndex -1);
        quick_sort(list, pivotIndex+1, right);
    }

}