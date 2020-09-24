#include <iostream>

using namespace std;

int cache[101];
int size;

int upstair(int n){

    int& ret = cache[n];
    if(ret != -1) return ret;
  
    // upstair(0) = 1 이 되어야 올바르게 작동함.
    //if( n == 0 ) return 0;
    if( n < 2) return 1;
    return ret = upstair(n-1) + upstair(n-2);
    
}

int main(void){
    int n;
    cin >> n;

    memset(cache, -1, sizeof(cache));

    int result = upstair(n);
    cout << result << endl;
    return 0;
}