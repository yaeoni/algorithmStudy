#include <stdio.h>
#include <stdlib.h>

#define MAX 999999
int main(void){

    int n, m, ary[101], temp;
    int ans = 0; 
    int i, j, k ;  

    scanf("%d %d", &n, &m);

    for( i = 0 ; i < n ; i++)
        scanf("%d", &(ary[i]));
    

    for( i = 0 ; i< n-2 ; i ++){
        for( j =i+1 ; j < n-1 ; j++ ){
            for( k = j+1 ; k < n ; k++ ){
                temp = ary[i] + ary[j] + ary[k];
                
                if(ans < temp && temp <= m)
                    ans = temp;
            }
        }
    }

    printf("%d", ans);

    return 0;
}