/*
- 분명 풀어봤고 뭔가 기막힌 방법이 있었던 것 같은데....... 기억이 안나!!
- 하나의 배열로 풀이했던 것 같은디ㅠ -> 아니여 ㅠ 
- 윽..ㅡ으으으으윽!!! 고통스럽다..

[ 2, 1, 3, 2 ] --정렬하면--> [ 3, 2, 2, 1 ] + 앞서 위치한 아이가 먼저 실행됨
- 우선순위 배열 / 정렬배열 두 개 두고 
- 정렬배열에서 pop 시키면서 해당 값을 가진 idx를 우선순위 배열에서 순차적으로 찾아서???
- 찾으면 -1 처리 해주고 뒤로 넘어가기,,,
=> 이러면 똑같은 값을 가지고 있는 경우에 처리할 수 없다.

[검색]
- 인쇄 대기목록을 "순차적"으로 처리한다.(순차적으로 매번 몇 번째에 프린트 되는지 판별)
- 우선순위큐(우선순위 정렬, pop을 위한 듯) / 큐(인덱스 번호 & 우선순위 기억) 이용
    => 하나의 배열로 처리는 개뿔이었네..
- 이때 우선순위큐로 선언하게 되면 기본적으로 max heap이라 정렬되어나옴
- 
*/
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    for(int i = 0 ; i < priorities.size() ; i++){
        q.push(make_pair(i, priorities[i]));
    }
    sort(priorities.begin(), priorities.end());
    
    while(!q.empty()){
        // 해당 idx는 문서의 위치를 의미(location)
        int idx = q.front().first;
        int value = q.front().second;
        q.pop();
        
        // 우선순위가 가장 높은 문서라면 
        if(value == priorities.back()){
            priorities.pop_back();
            answer++;
            
             if(idx == location){
                break;
            }
        // 가장 높은 우선순위의 문서가 아니라면 -> 큐 끝에 다시 삽입한다.
        }else{
            q.push(make_pair(idx, value));
        }
    }
    return answer;
}