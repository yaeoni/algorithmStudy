#include <stdio.h>

int num = 10;
int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quick_sort(int* data, int start, int end);

int main(void){

    quick_sort(ary, 0, num-1);

    for(int i = 0; i < 10; i ++)
        printf("%3d", ary[i]);

    return 0;
}

void quick_sort(int* data, int start, int end){
   
    /* if the num of data is 1 */ 
    if(start >= end)
        return;

    int key = start; // = pivot

    int i = start + 1; // bigger value than pivot
    int j = end; // smaller valu e
    int temp;

    /* untill crossed */
    while( i <= j ){

        while(data[i] < data[key])
            i++; 
        while(data[j] > data[key] && j > start ) // be careful to not over the range of ary.
            j--;

        if( i > j ){

            // swap data[j] (smaller value) with pivot
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }else{
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }

         quick_sort(data, start, j-1); // left
         quick_sort(data, j+1, end); // right
    }

}