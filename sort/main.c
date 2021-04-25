#include<stdio.h>
#include "sort.h"
#include <time.h>

struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};

int main(){
    struct timeval start, end;

    int ten[10];
    for(int i = 0 ; i < 10; i++){
        ten[i] = 10-i;
    }

    int hundred[100];
    for( int i = 0 ; i < 100; i++){
        hundred[i] = 100-i;
    }

    int thousand[1000];
    for( int i = 0 ; i < 1000; i++){
        thousand[i] = 1000-i;
    }

    int ten_thousand[10000];
    for( int i = 0 ; i < 10000; i++){
        ten_thousand[i] = 10000-i;
    }

    gettimeofday(&start,NULL);
    /*--100--*/
    //bubble_sort(hundred, 100);
    //quick_sort(hundred, 0, 99);
    //insertion_sort(hundred, 100);
    //merge_sort(hundred, 0, 99);
    //bucket_sort(hundred, 100, 10);
    //radix_sort(hundred, 100);
    gettimeofday(&end,NULL);
    //for (int i = 0; i < 100; i++) printf("%d ", hundred[i]);

	
    /*--1000--*/
    //bubble_sort(thousand, 1000);
    //quick_sort(thousand, 0, 999);
    //insertion_sort(thousand, 1000);
    //merge_sort(thousand, 0, 999);
    //bucket_sort(thousand, 1000, 20);
    //radix_sort(thousand, 1000);
    //end = clock();
    //for (int i = 0; i < 1000; i++) printf("%d ", thousand[i]);
	
    /*--10000--*/
    //bubble_sort(ten_thousand, 10000);
    //quick_sort(ten_thousand, 0, 9999);
    //insertion_sort(ten_thousand, 10000);
    //merge_sort(ten_thousand, 0, 9999);
    //bucket_sort(ten_thousand, 10000, 50);
    //radix_sort(ten_thousand, 10000);
    //end = clock();
    //for (int i = 0; i < 10000; i++) printf("%d ", ten_thousand[i]);
	
    //printf("\nRunning time : %f micro second\n", (float)end-start);
    return 0;
}