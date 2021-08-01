/*
- 날짜 count
- 매 날짜마다 해당 speeds들 추가
- 100이상인 것들 pop(0) <- 이거 너무 오버헤드가 크다. 
    파이썬에선 디큐로 만들면 된다지만 c++에선 무엇을 활용해야할지 ?!
- 이때 한 번에 팝되는 얘들의 개수를 넣으면 된다.
    
[ 내 생각 ]
- 완료된 일을 모아놓는 벡터를 만들고 그 합이 기존 길이랑 같으면 리턴

-> 마지막 테케에서 걸린다. 100 이상인데, 100 초과로 설정해놔서 그렇다.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
        
    int count = 0;
    int start = 0;

    while(count != progresses.size()){
        
        int end = 0;
        for(int i = start ; i < progresses.size() ; i++){
            progresses[i] += speeds[i];
            
            // 작업 후 하루의 끝 ( 100이 넘었는가? 판단 )
            if( i == start && progresses[i] >= 100){
                end++;
                start++;
                count++;
            }
        }
        if(end !=0){
            answer.push_back(end);
        }
    }
    return answer;
}