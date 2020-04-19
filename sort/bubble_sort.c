#include <stdio.h>

/* Bubble sort */

int main(void){

    // Don't need 'min' variable

    int i, j, temp;

    int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

    for(i = 0 ; i < 10 ; i++){

        for(j = 0 ; j< 9-i; j++){
            if(ary[j] > ary[j+1]){
                temp = ary[j];
                ary[j] = ary[j+1];
                ary[j+1] = temp;
            }
        }
        
    }

    for(i = 0 ; i < 10 ; i++)
        printf("%3d", ary[i]);
      
    /* yaewon 
    int i, j , min, temp;

    int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

    for( i = 0; i < 10 ; i ++){
       
       min = ary[i];

       for( j = 0 ; j < 9-i ; j++){

           // Have to compare with 'j', not i
           // 'i' is for iteration
           
           if( min > ary[j]){
               temp = min;
               min = ary[j];
               ary[j] = min;
           }

       }
    }
     yaewon */

    return 0;
}