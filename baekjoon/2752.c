#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* data, int num);
void bubble_sort(int* data, int num);
void insertion_sort(int* data, int num);
void quick_sort(int* data, int start, int end);

int main(void){

    int* ary;

    ary = (int*)malloc(sizeof(int)*3);

    for(int i = 0; i < 3 ; i++){
        scanf("%d", &ary[i]);
    }

    quick_sort(ary, 0, 2);

    for(int i = 0 ; i < 3; i++)
        printf("%d ", ary[i]);

    return 0;
}

void selection_sort(int* data, int num){

    int temp, min, index;
    
    min = 1000000;

    for( int i = 0; i<num ; i++){

        for( int j = i ; j < num ; j++){

            if(data[j] < min){
                min = data[j];
                index = j; 
           }
        }

        temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
}

void bubble_sort(int* data, int num){

    int temp;

    for( int i = 0 ; i < num ; i++){

        for( int j = 0 ; j < num - i ; j++){
            if( data[j] > data[j+1]){

                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }

        }
    }

}

void insertion_sort(int* data, int num){

    for( int i = 0 ; i < num ; i++){

        int j = i;

        while( j >= 0 && data[j] > data[j+1]){

            int temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
            j--;

        }
    }
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