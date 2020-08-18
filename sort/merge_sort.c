#include <stdio.h>

int num = 8;
int sorted[8]; // ** sorted array must be a global variable.


void merge_sort(int a[], int m, int n);
void merge(int a[], int m, int middle, int n);

int main(void){


    int ary[8] = { 1, 10, 5, 8, 7, 6, 4, 3};
    merge_sort(ary, 0, num-1);

    for(int i = 0 ; i < num ; i++)
        printf("%3d", ary[i]);

    return 0;
}

void merge(int a[], int m, int middle, int n){

    int i = m;
    int j = middle + 1;
    int k = m;

    while( i <= middle && j <= n){

        if(a[i] <= a[j]){
            sorted[k] = a[i];
            i++;
        }else {
            sorted[k] = a[j];
            j++;
        }

        k++;
    }

    /* Insert rest data in sorted array */

    // when i is completed first
    if( i >  middle){
        for( int t = j ; t < n ; t++ ){
            sorted[k] = a[t];
            k++;
        }
    }else {
        for( int t = i ; t< middle ; t++){
            sorted[k] = a[t];
            k++;
        }
    }


    /* Insert sorted array into 'origin' array */
    for( int t = m ; m < n ; m++){
        a[t] = sorted[t];
    }

}


void merge_sort(int a[], int m, int n){

    int middle;

    if( m<n ){
        middle = ( m+n )/2;

        merge_sort(a, m, middle); // split
        merge_sort(a, middle+1, n);

        merge(a, m, middle, n); // merge

    }
}
