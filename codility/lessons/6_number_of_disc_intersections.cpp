/*
- array 요소들 : 디스크의 radius(반지름)
- j 번째 디스크 -> (j,0)에 센터 / 반지름
- J와 K intersect다/ j, k 디스크가 하나의 공통 포인트 가질때.(경계포함)
- intersecting disc의 수 리턴 / 10^7 넘으면 -1 
- 어떤식으로 접근해야하나! 원의 중심이 좌표따라 달라짐.
- 양 끝점을 기억해서 내부에 들어가는지 보기.. => n^2 우선 이거라도 해보겠다.
- 일단 소팅으로 분류되어있긴한데, 소팅이 어디에 쓰이는지? ㅎ

=> 81% ! 일단 방법이 생각나지 않으면 브루트 포스 방법이라도 코드를 짜야한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<pair<long, long>> discs;

int solution(vector<int> &A) {
    if(A.size() < 2) return answer;

    for(auto i = 0 ; i < A.size() ; i++){
        long radius = A[i];
        discs.push_back({i-radius, i+radius}); // 디스크 원 위치 삽입
    }

    sort(discs.begin(), discs.end());

    // 작은 원부터 포함되는 영역이 있는지
    // 양 옆 점중 오른쪽 점이 내 뒤의 원의 왼쪽 점보다 바깥에 있으면 포함. 아하
    for(auto i = 0 ; i < discs.size()-1 ;i++){
        long right = discs[i].second;
        for(auto j = i+1 ; j < discs.size() ; j++){
            if(right >= discs[j].first) answer++;
        }
    }

    return answer;
}