/*
- 각 날마다의 최댓값 기억하기
- d, p (d 일 내로, p원 지급)

=> 배열로 매번 iterate하면서 최대값을 체크하면 o(n^2),, 비효율적인걸.
=> 자료구조 생각해보기 => priority_queue

- 강연할 수 있는 날짜에 제한이 있다.
- 강연 금액이 큰 것이 될 수 있는 한 큰 날짜로 가야한다...
=> 이 까지 하고 방법이 떠오르지 않았다.

[검색]
- 날짜기준(d) 정렬
- pq(min heap)에 p 삽입 & result 갱신
- pq의 크기 > pop된 d 라면(일 수가 겹친다면) 최소값 삭제 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first; //오름차순
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<pair<int, int> > v;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int d, p;
        cin >> p >> d;
        v.push_back({d,p});
    }
    
    // 날짜 기준 정렬
    sort(v.begin(), v.end(), cmp);


    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // pq, 오름차순 정렬

    for(int i = 0 ; i < n ; i ++){
        // 금액 추가
        pq.push(v[i].second);
        result += v[i].second;

        if(pq.size() > v[i].first){
            // 겹치면
            result -= pq.top();
            pq.pop();

        }    
    }

    cout << result <<  "\n";
    return 0;
    
}