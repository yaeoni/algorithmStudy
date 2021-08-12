/*
- dfs, bfs 를 이용해 결과가 target이면 answer에 더하는형식
- 이번엔 c++을 bfs로 구현해보도록 합시다

- bfs <- queue를 이용해서 구현
*/
#include <string>
#include <vector>
#include <queue>

#include <iostream>
using namespace std;

int solution(vector<int> numbers, int target) { 
    int answer = 0;
    
    //넣을 숫자 인덱스
    int size = numbers.size()-1;
    queue<pair<int, int>> q;
    
    // 시작 세트 초기화
    q.push(make_pair(0, numbers[0]));
    q.push(make_pair(0, -numbers[0]));
    
    int count = 0;
    
    while(!q.empty()){
        count ++;
        pair<int, int> p = q.front();
        q.pop();
        
        if(p.first == size && p.second == target) {
            answer++;
        }
        
        if(p.first < size){
            int idx = ++p.first;
            q.push(make_pair(idx, p.second+numbers[idx]));
            q.push(make_pair(idx, p.second-numbers[idx]));  
        }
    }
    return answer;
}