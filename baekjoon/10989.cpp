#include <iostream>
#define MAX 10001
#include <vector>

using namespace std;

/* counting sort */

int main(void){

    int n;

    vector<int> count;

    cin >> n;

    count.assign(MAX, 0);

    for( int i = 0; i < n ; i++ ){
        int num ;
        scanf("%d", &num);
        count[num]++;
    }
    for( int i = 0 ; i < MAX ; i++){
        for( int j = 0 ; j < count[i] ; j++){
            printf("%d\n", i);
        }
    }

    return 0;
}