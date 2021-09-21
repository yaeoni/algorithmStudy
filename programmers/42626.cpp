/*
- 매번 소팅하면서 스코빌 지수 만들어내기,,?
- 모든 음식 만들 수 없는 경우 = 1개 남았고, 그것마저도 K보다 작을 때
- 매번 pop을 해야하는데, reverse 시켜서 하는게 그나마 덜! 오버헤드.
=> 기본 테스트는 통과하지만 효율성에서는 역시,,,, 모두 시간 초과 ,, ㅎㅎ

- 가장 작은 값을 찾아내면 된다 항상.
    => 이래서 Min heap을 사용하는가?
    => 우선순위 큐(기준: 가장 낮은값) 활용!!!
*/
#include <string>
#include <vector>

#include <algorithm>

#include<iostream>
using namespace std;

int solution(vector<int> scoville, int K) {

    int answer = 0;
    
    sort(scoville.begin(), scoville.end(), std::greater<>());
    
    
    while(scoville.size() > 0){
        if(scoville.size() == 1 && scoville[0] < K) return -1;
        if(scoville[scoville.size()-1] >= K) break;
        
        int idx = scoville.size() - 1;
        
        int newS = scoville[idx] + scoville[idx-1]*2;
        
        scoville.pop_back();
        scoville.pop_back();
        
        scoville.push_back(newS);
        answer++;
        
        sort(scoville.begin(), scoville.end(), std::greater<>());
    }
    
    return answer;
}

/*
- 효율성 높인!! 우선순위큐를 잊지마 , ,,
- 가장 작은 값을 찾아내면 된다 항상.
    => 이래서 Min heap을 사용하는가?
    => 우선순위 큐(기준: 가장 낮은값) 활용!!!

- priority queue 우선순위(3번째 매개변수)는
    greater<int>, less<int>, or operator 오버로딩이 필요
    bool operator < (어쩌구){
        return 블라블라..
    }
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include<iostream>
using namespace std;

int solution(vector<int> scoville, int K) {

    int answer = 0;
    
    // 우선순위 기준 -> 오름차순.
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    // 아직 섞을 수 있고(원소가 2개 이상), 최소값이 K 보다 작다면.
    while(pq.size() > 1 && pq.top() < K){
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        pq.push(first + 2*second);
        answer ++;
    }
    
    if(pq.top() < K){
        return -1;
    }
    return answer;
}