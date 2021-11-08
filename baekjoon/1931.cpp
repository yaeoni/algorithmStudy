/*
- 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 

- 모든걸 다 정렬해서 생각한다. => 최악!

- 반례를 선택하라했다!!!!

- 회의 시작 시간이 제일 빠른 것을 선택한다.
    - 회의 끝 시간이 졸라게 길어버리면 하나밖에 못듣는다.

- 회의 진행 시간이 가장 짧은 것 선택
    - 중구난방

- 회의 끝나는 시간이 가장 빠른 것 선택.
    -> 이거다.
    - 회의 끝나는 시간이 같다면, 뭘 하던 상관은 없을것 같지만 시작 시간이 빠르면 좋겠지.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

int N;
int startTime, endTime;
vector<pair<int, int>> conf;

int e = 0; // 끝나는 시간

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 입력 받기
    cin >> N;

    while (N--)
    {
        cin >> startTime >> endTime;
        conf.push_back({startTime, endTime});
    }

    sort(conf.begin(), conf.end(), comp);

    for (auto v : conf)
    {
        if (v.first >= e) // 끝난 시간보다 시작 시간이 늦거나 같다면 회의가능
        {
            e = v.second;
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}
