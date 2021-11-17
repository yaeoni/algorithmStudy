/*
- 연속되지 않은, 순서대로의 . 공통 부분 수열
- DP는 냅다 따라 풀어보는 방식으로 하는게 내 정신건강에 이롭다.

- 하나씩 떼어가면서 진행시키면 공통 계산 부분이 많다.
- 진행하다 같은 문자를 찾으면 (기존 LCS길이 +1)

- 이중포문으로 2차원 배열 하나씩 채우면서 부분이 같아지는 부분에 +1
    => dp[i][j] = dp[i-1][j-1]+1 (현재 이전의 값)
- 다르다면 두 문자가 각 각 포함되지 않은 곳 중 max 값 그대로 가져오기
*/
#include <iostream>

using namespace std;

string first;
string second;
int ary[1001][1001] = {
    0,
};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> first >> second;

    for (int i = 1; i <= first.size(); i++)
    {
        for (int j = 1; j <= second.size(); j++)
        {
            if (first[i - 1] == second[j - 1]) // string접근이라 index-1로 접근.
            {
                ary[i][j] = ary[i - 1][j - 1] + 1;
            }
            else
            {
                ary[i][j] = max(ary[i][j - 1], ary[i - 1][j]);
            }
        }
    }

    cout << ary[first.size()][second.size()] << "\n";

    return 0;
}