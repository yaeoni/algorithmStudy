#include <stdio.h>

int main(void){

    int i, j, temp;

    int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

    //compare with first value

    for( i = 0; i< 9 ; i++){
        j = i;
            while( ary[j] > ary[j+1]){
                temp = ary[j+1];
                ary[j+1] = ary[j];
                ary[j] = temp;
                j--; 
            }


    }
    for( i = 0 ; i<10 ; i++)
        printf("%3d", ary[i]);

    /* yaewon

    //compare with last value - wrong ( Because of insertion sort's assumption. )

    for( i = 1 ; i < 10 ; i++){

        for(j = 0 ; j < i ; j++){
            if( ary[i] < ary[j]){
                temp = ary[j];
                ary[j] = ary[i];
                ary[i] = temp;
            }

        }
    }

    for( i = 0 ; i<10 ; i++)
        printf("%3d", ary[i]);

    yaewon */

    return 0;
}