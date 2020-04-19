#include <stdio.h>

/* Selectin sort */

int main(void){

	int i, j, min, temp, index;

	int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for( i = 0 ; i < 10 ; i++ ){

		min = 9999;
		
		for( j = i ; j < 10 ; j++ ){
			if( ary[j] < min){
	
				min = ary[j]; //find smallest value
				index = j;
			}
		}

	/* swap min <-> current value */

		temp = ary[i];
		ary[i] = ary[index];
		ary[index] = temp;

	}
	
	for( i = 0 ; i < 10 ; i++)
		printf("%3d", ary[i]);
	return 0;

}
