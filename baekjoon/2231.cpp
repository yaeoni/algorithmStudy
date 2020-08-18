#include <iostream>
#define MAX 1000001
using namespace std;

int check[MAX] = {0,};

int main(void){

    int n;
    int ans = 0;
    cin >> n;

    for( int i = n/2 ; i < MAX ; i++ ){

        int val = i;
        int sum = val;

        while( val != 0 ) {
            //get decomposition
            sum += val % 10;
            val = val/10;
        } 

        if( sum == n ){
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}