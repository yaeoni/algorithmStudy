#include<stdio.h>
#include "sort.h"
#include <sys/time.h>
#include <stdlib.h>


void ary_init(int* hundred, int* thousand, int* ten_thousand){

    for( int i = 0 ; i < 100; i++){
        hundred[i] = 100-i;
    }
    
    for( int i = 0 ; i < 1000; i++){
        thousand[i] = 1000-i;
    }


    for( int i = 0 ; i < 10000; i++){
        ten_thousand[i] = 10000-i;
    }

}

int main(){

    int hundred[100];
    int thousand[1000];
    int ten_thousand[10000];

    struct timeval start, end;

    int bubble_time[3]= {0};
    int insert_time[3] ={0};
    int merge_time[3] = {0};
    int quick_time[3]= {0};
    int radix_time[3] = {0};
    int bucket_time[3]= {0};

    int temp;

    printf("         n=100  n=1000  n=10000\n");    
    ary_init(hundred, thousand, ten_thousand);

    /*--bubble sort--*/
    printf("Bubble    ");
    gettimeofday(&start,NULL);
    bubble_sort(hundred, 100);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    bubble_time[0] = temp;

    gettimeofday(&start,NULL);
    bubble_sort(thousand, 1000);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    bubble_time[1] = temp;

    gettimeofday(&start,NULL);
    bubble_sort(ten_thousand, 10000);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    bubble_time[2] = temp;

    for(int i =0;i<3;i++){
        printf("%d     ", bubble_time[i]);
    }
    printf("\n");

    ary_init(hundred, thousand, ten_thousand);


    
    /* insertion sort */
    printf("insertion ");
    gettimeofday(&start,NULL);
    insertion_sort(hundred, 100);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    insert_time[0] = temp;

    gettimeofday(&start,NULL);
    insertion_sort(thousand, 1000);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    insert_time[1] = temp;

    gettimeofday(&start,NULL);
    insertion_sort(ten_thousand, 10000);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    insert_time[2] = temp;

    for(int i =0;i<3;i++){
        printf("%d     ", insert_time[i]);
    }
    printf("\n");

    ary_init(hundred, thousand, ten_thousand);
    

    /* merge sort */
    printf("merge      ");
    gettimeofday(&start,NULL);
    merge_sort(hundred, 0, 99);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    merge_time[0] = temp;

    gettimeofday(&start,NULL);
    merge_sort(thousand, 0, 999);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    merge_time[1] = temp;

    gettimeofday(&start,NULL);
    merge_sort(ten_thousand, 0, 9999);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    merge_time[2] = temp;

    for(int i =0;i<3;i++){
        printf("%d       ", merge_time[i]);
    }
    printf("\n");

    ary_init(hundred, thousand, ten_thousand);

    /* quick sort */
    printf("quick     ");
    gettimeofday(&start,NULL);
    quick_sort(hundred, 0, 99);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    quick_time[0] = temp;

    gettimeofday(&start,NULL);
    quick_sort(thousand, 0, 999);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    quick_time[1] = temp;

    gettimeofday(&start,NULL);
    quick_sort(ten_thousand, 0, 9999);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    quick_time[2] = temp;

    for(int i =0;i<3;i++){
        printf("%d     ", quick_time[i]);
    }
    printf("\n");

    ary_init(hundred, thousand, ten_thousand);

    /* radix sort */
    printf("radix      ");
    gettimeofday(&start,NULL);
    radix_sort(hundred, 100);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    radix_time[0] = temp;

    gettimeofday(&start,NULL);
    radix_sort(thousand, 1000);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    radix_time[1] = temp;

    gettimeofday(&start,NULL);
    radix_sort(ten_thousand, 10000);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    radix_time[2] = temp;

    for(int i =0;i<3;i++){
        printf("%d     ", radix_time[i]);
    }
    printf("\n");

    ary_init(hundred, thousand, ten_thousand);

    /* bucket sort */
    printf("bucket     ");
    gettimeofday(&start,NULL);
    bucket_sort(hundred, 100, 10);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    bucket_time[0] = temp;

    gettimeofday(&start,NULL);
    bucket_sort(thousand, 1000, 20);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    bucket_time[1] = temp;

    gettimeofday(&start,NULL);
    bucket_sort(ten_thousand, 10000, 50);
    gettimeofday(&end,NULL);
    temp = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec- start.tv_usec);
    bucket_time[2] = temp;

    for(int i =0;i<3;i++){
        printf("%d     ", bucket_time[i]);
    }
    printf("\n");

    printf("\nTime type is microseconds\n");
    return 0;
}