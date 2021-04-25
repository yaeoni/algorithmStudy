#include <stdio.h>
#include "sort.h"

/**
 * when input is n, the bucket size is..
 * 100 -> 10
 * 1000 -> 20
 * 10000 -> 50
 */

// buck_size = bucket's number
void bucket_sort(int* ary, int size, int buck_size){
    int bucket[buck_size][size];
    int buck_count[buck_size];
    int capacity = size / buck_size;
    int i , j;
    
    for(i = 0 ; i < buck_size; i++){
        buck_count[i]= 0;
    }

    for(i = 0 ; i < size; i++){
        int idx = (ary[i]+capacity-1)/capacity -1;
	   bucket[idx][buck_count[idx]] = ary[i];
	   buck_count[idx]++;
    }
    
    for (i = 0; i<buck_size; i++) 
		insertion_sort(bucket[i], buck_count[i]);

    int ary_idx = 0;
	for (i = 0; i < buck_size; i++){
		for (j = 0; j < buck_count[i]; j++){
			ary[ary_idx++] = bucket[i][j];
		}
	}
}