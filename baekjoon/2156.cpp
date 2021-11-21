/*
- 잔 선택하면 무조권 마셔야함. / 마신 후에는 제자리에
- 연속 3잔은 못 마신다.

- dp[n] : 효주가 마신 최대 포도주의 양

- 케이스 => 아하.
1. 지금 마심 * 대신 이전 포도주 안마심
2. 지금 마심 * 이전도 마심 * 전전은 안마심
3. 지금을 안마심

위의 1,2,3 중 최댓값을 리턴하기

dp[n] = max(arr[n]+dp[n-2], arr[n]+arr[n-1]+dp[n-3], dp[n-1])

=> 아래서부터 채워나갈 수 있다!
=> 주어진 포도주 양을 가지고!
*/
#include <iostream>

using namespace std;

int answer;
int dp[10001];

int n;
int arr[10001];


int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 1 ; i <= n ; i++) cin >> arr[i];
    
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3 ; i <= n ; i++){
        dp[i] = max(arr[i]+dp[i-2], max(arr[i] + arr[i-1] + dp[i-3], dp[i-1]));
    }
    
    cout << dp[n] << "\n";
    return 0;
}