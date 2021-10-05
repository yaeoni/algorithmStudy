/*
- 작업의 요청부터 종료까지 걸린 시간의 평균을 가장 줄이는 방법

- "실행할 수 있으면서 가장 짧은실행시간의 task" 배치 => 이게 맞았다. ! 코드 구현에 겁먹어서,,

- 가장 짧은 실행시간 정렬 pq
- 요청 시간순 정렬(jobs) -> 진행 상황은 index로 이동

- 가장 먼저 들어온 것부터 수행

- queue 를 이용한 max, min heap
- 마지막 매개변수에 정렬 기준 넣을 수 있음(bool 함수)
- 내림차순(max) priority_queue<int> pq;
- 오름차순(min) priority_queu<int, vector<int>, greater<int>> pq;

=> 해당 문제에서는 요소가 1차원 벡터에 min heap 구현해야하니까
    priority_queue< vector<int>, vector<vector<int>>, bool> pq;
    
결론 : jobs는 항상 pq를 통해서 수행되는거임!
*/

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#include <iostream>

using namespace std;

// 실행시간 기준 min heap(내림차순)
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    priority_queue< vector<int>, vector<vector<int>>, cmp> pq;
    
    int idx = 0;
    int time = 0;
    // 아직 남은 작업이 있다면
    while(!pq.empty() || idx < jobs.size() ){
        // 수행할 수 있는 작업이 있고 && 이 작업이 끝난 다음에 바로 실행할 수 있따면
        // = 시작 시간이 수행시간 사이에 낑긴다면
        // => 우선순위 큐에 대기 시킨다.
        if(idx < jobs.size() && time >= jobs[idx][0]){
            pq.push(jobs[idx++]);
            continue; // 더 있을 수 있으니 continue
        }
        
        // 우선순위 큐 처리
        if(!pq.empty()){
            // 작업 수행
            time += pq.top()[1];
            
            // 기다린 총 시간(answer)에 추가 (현재 시간 - 요청한 시간)
            answer += time - pq.top()[0];
            pq.pop();
        }else{
            // 큐 속에 대기하고 있는게 없다면 바로 다음 작업 시간으로 넘김
            time = jobs[idx][0];
        }
    }
    // 전체 시간을 task수로 나눔
    return answer/ jobs.size();
}