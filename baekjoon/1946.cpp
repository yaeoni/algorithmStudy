/*
- 최고의 인재만을 선발하겠따.
- 다른 모든 지원자와 비교했을 때 서류, 면접 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발
    => 문제를 잘 이해 못하는중,, 아하. 순위구나
    => 내 점수보다 둘 다 낮은애가 있다면 떨어진다.
        => 이걸 알고리즘적으로 어떻게 풀어가야되려나? ,, 고민중 난 왜케 곱하기를하고싶지 ㅋ

    => 하나를 기준으로 잡고, 나머지 하나로 판단하기?
        => 내림차순으로 하면 무족권 다음 요소보다 순위가 낮음 , 하나만 더 낮으면 된다.
        => 이것도 결국 이중포문인디,, => 역시 시간초과났다.
        => 아 미띤... 오름차순으로 해서 포문 한 번으로 끝낼 수 있었ㄷ드아아악!!!
        => 두번째 요소가 기준보다 크면 pass, 작으면 answer++ 하면서 기준 업데이트..하 ... 거의다왔었다..그래두ㅠ

    => 고민고민고민ㄱ고민 그리디그리디그리디,,
- N 이 10만이라 이중포문은 안된다.

- 테케 문제 -> 한 줄에 뽑는 최대 인원수 출력
- 동석차는 없다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T; // 테스트 케이스 수
int N; // 지원자의 숫자

int s; // 서류 심사 ^순위^
int m; // 면접 심사 ^순위^
int answer;

vector<pair<int, int>> v;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        cin >> N;
        answer = 0;
        v.clear();

        while (N--)
        {
            cin >> s >> m;
            v.push_back({s, m});
        }
        sort(v.begin(), v.end());

        int comp = v[0].second;
        answer++;

        for (int i = 1; i < v.size(); i++)
        {
            if (comp < v[i].second)
                continue;

            comp = v[i].second;
            answer++;
        }

        cout << answer << "\n";
    }

    return 0;
}