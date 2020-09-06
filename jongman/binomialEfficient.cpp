#include <iostream>

using namespace std;

/* Dynamic Programming */
/* Bino efficient, nCr */

int bino(int n, int r){
    
    //기저 사례
    if(n == r || r == 0)
        return 1;
    return bino( n-1, r) + bino(n-1, r-1);

}

int cache[30][30] = { -1, };
int optimizedBino(int n, int r){

    //기저 사례
    if(n == r || r == 0)
        return 1;
    
    // 이미 호출되었다면 그대로 리턴
    if(cache[n][r] != -1 )
        return cache[n][r];
    
    // 비어있다면 값 할당하면서, 계산하면서, 재귀로 리턴
    return cache[n][r] = optimizedBino(n-1, r-1) + optimizedBino(n-1, r);

}

int main(void){

    int n, r, result;
    
    cin >> n;
    cin >> r;

    result = optimizedBino(n, r);

    return 0;
}