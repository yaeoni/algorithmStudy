/*
- 입.퇴실 동시에 이뤄지는 경우는 없음
- 입실 [1, 2] 퇴실 [2,1]
- (1기준) 입실을 먼저 했는데, 퇴실을 더 늦게하면 "반드시" 만남

- 각 사람별로 반드시 만난 사람은 몇명인가?

[예원]
- 내 입실 index와 퇴실 index를 비교한다?!
- (먼저 들어온 기준)내 입실 index < 상대 입실 index && 내 퇴실 index > 상대 퇴실 index 면 만난다
- (나중에 들어온 기준)내 입실 index > 상대 입실 index && 내 퇴실 index < 상대 퇴실 index

ex)
#1
(3기준) 1 < 2 / 2 > 1
(2기준) 2 > 1 / 1 < 2
=> 역시 아니었다!!!!!!! 힝. 힝힝 힝 힝 힝 힝

[검색]
1. 회의실 아무도 없다 -> 입실
2. 퇴실 할 수 있는 사람이 생길 때까지 -> 입실
3. 퇴실처리
4. 3에서 퇴실한 사람은 회의실에 남아있던 사람들과 반드시 만남.

WOW 이런 생각은 자주 풀다보면 얻을 수 있는걸까,,,,

*/

#include <iostream>

#include <vector>
#include <algorithm>
#include <queue> // 입실, 퇴실 관리(순서 popleft 되므로 queue 사용)
using namespace std;

vector<int> solution(vector<int> e, vector<int> l) {
	vector<int> answer(e.size());

	vector<int> conf;
    
    queue<int> enter;
    queue<int> leave;
    
    for(auto p : e) enter.push(p);
    for(auto p : l) leave.push(p);
    
    while(!leave.empty()){
        if(conf.empty()){
            conf.push_back(enter.front());
            enter.pop();
        }
        
        // 아직 사람이 들어올 수 있고, 퇴실할 수 있는 사람이 생길 때까지 입실
        // c++ 에서는 value로 index 찾기 고달프므로 iterator 열심히 활용
        auto iter = find(conf.begin(), conf.end(), leave.front());
                         
        while( !enter.empty() && iter == conf.end()){
            conf.push_back(enter.front());
            enter.pop();
            
            iter = find(conf.begin(), conf.end(), leave.front());
        }
        
        // 퇴실
        int out = leave.front();
        leave.pop();
        conf.erase(iter);
        
        for(auto p : conf){
            if(p != out){
                answer[p-1] +=1;
                answer[out-1] +=1;
            }
        }
    }
	return answer;
}