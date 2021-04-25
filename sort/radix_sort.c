#include <stdio.h>
#include "sort.h"
#include<time.h>

void count_sort(int *ary, int size, int exp){
	int ret[size];
	int count[10] = {0};
    int i;

	for (i = 0; i < size; i++)
		count[(ary[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i-1];

	for (i = size-1; i >= 0; i--){
		ret[count[(ary[i]/exp) % 10]-1] = ary[i];
		count[(ary[i]/exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		ary[i] = ret[i];
}

void radix_sort(int *ary, int size){
	int max = 0;
    
    // get max value
	for (int i = 0; i < size; i++){
		if (ary[i] > max){
			max = ary[i];
		}
	}
    // i = exponential
	for (int i = 1; max/i > 0; i *= 10){
		count_sort(ary, size, i);
	}
}