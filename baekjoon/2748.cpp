/*
- DP 사용하는 피보나치
- dp 값 자체에 fibo 함수를 call 하는 방식을 사용한다!
*/

#include <iostream>

using namespace std;

int n;

long long dp[91] = {0,};

long long fibo(int n)
{

    if (n == 1 || n == 2) return 1;

    if (dp[n] != 0)
    {
        return dp[n];
    }
    else
    {
        dp[n] = fibo(n - 1) + fibo(n - 2);
    }
    return dp[n];
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    cout << fibo(n) << "\n";

    return 0;
}