#include <stdio.h>
#include <stdlib.h>


/*  Actually, Quick sort can't solve this problem due to o(n^2) in worst case
    So, we have to use sort() function of C++ STL Library.   */

void quick_sort(int* data, int start, int end);

int main(void){

    int num;
    int* ary;

    scanf("%d", &num);

    ary = (int*)malloc(sizeof(int)*num);

    for(int i = 0; i < num ; i++){
        scanf("%d", &ary[i]);
    }

    /* C++ STL Library  / #include <algorithm> */
    //std::sort(ary, ary+num);

    quick_sort(ary, 0, num -1);
    
    for(int i = 0 ; i < num; i++)
        printf("%d ", ary[i]);

    return 0;
}

void quick_sort(int* data, int start, int end){

    int temp;

    if(start >= end)
        return;
    
    int pivot = start;

    int i = start+1;
    int j = end;

    while( i <=j ){

        while( data[i] < data[pivot])
            i++;
        while( data[j] > data[pivot])
            j--;
        
        if( i <= j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }else{
            temp = data[pivot];
            data[pivot] = data[j];
            data[j] = temp;

        }

        quick_sort(data, start, j-1);
        quick_sort(data, j+1, end);

    }


}