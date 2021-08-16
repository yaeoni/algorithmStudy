/*
- 현재 다리에 올라갈 수 있는 트럭 파악 / 무게 파악
- 1초당 1씩 지나가니까, 현재 지나가고 있는 위치 파악
- bridge_length 만큼 지나가면 다리 다 건넘.
- 근데 한번에 한대씩만 올라가네

- 어찌 어찌 풀어내긴 했는데, 1초 경과하면서의 flow를 잘 파악해야할 것 같다 항상! 
- 내일은 다른사람의 풀이로 python 으로 풀어보자
*/
#include <string>
#include <vector>
#include <utility>

#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<pair<int, int>> trucks;
    for(int t: truck_weights) trucks.push_back(make_pair(t, 0));
    
    // 다리에 올라간 트럭 & 다리 다 건넌 트럭 idx 두 개를 활용 해야함.
    int finish = 0;
    int truckIdx = 0;
    int curWeight = 0;

    while(1){
        if(finish == trucks.size()) break;
        
        answer++; // 1초 경과
        
        if(truckIdx < trucks.size()){
            if(curWeight+trucks[truckIdx].first <= weight){
                curWeight += trucks[truckIdx].first;
                truckIdx++;
            }
        } 
        
        // 이동거리 체크 & 확인
        for(int i = 0 ; i < truckIdx ; i++){
            trucks[i].second += 1; 
            if(trucks[i].second > bridge_length) continue;
            if(trucks[i].second == bridge_length){ 
                finish++;
                curWeight -= trucks[i].first;
            }
        }
    }
    return answer+1;
}