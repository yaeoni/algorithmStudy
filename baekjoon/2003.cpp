#include <iostream>
#define MAX 10001

using namespace std;

int ary[MAX];


int main(void){

    int n, m;

    scanf("%d %d", &n, &m);

    memset(ary, 0, sizeof(ary));

    for(int i = 0 ; i < n ; i++)
        scanf("%d", &ary[i]);

    int sum = 0, result =0, start = 0, end= 0;

    while(1){
        if(sum >= m){
            sum -= ary[start];
            start++;
        }
        else if( end == n){
            break;
        }
        else{
            sum += ary[end];
            end++;
        }

        if(sum == m) result++;
    }
    printf("%d", result);
    


    return 0;
}
