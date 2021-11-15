/*
- 동전을 적절히 사용해 가치의 합을 K로 만든다.
- 필요 동전 개수의 최솟값 구하기

- K <= 1억, int 써도 된다.

- 오름차순으로 주어진다!
- 주어지는 동전들은 매번 배수관계로 나타남
    => 어떻게 뽑든 채울 수 있음!!
    => 그리디로 쌉 가능
    => 큰 것 부터 뽑는다. => 뽑을 수 있는만큼 뽑는다.
*/

#include <iostream>
#include <vector>
using namespace std;

int N;
int K;

int temp;
int answer = 0;

vector<int> v;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    while (N--)
    {
        cin >> temp;
        v.push_back(temp);
    }

    int idx = v.size() - 1;

    while (K)
    {
        if (v[idx] > K)
        {
            idx--;
            continue;
        }
        K -= v[idx];
        answer++;
    }

    cout << answer << "\n";
    return 0;
}