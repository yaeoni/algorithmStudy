/*
- 그 예전에 물건 훔치는 알고리즘과 비슷한 것 같은데,, 그리디,,!
- 현 상황에서 가장 최선의 선택을 한다.

- 한 번에 최대 2명 & limit
- 모든 사람 구출하기 위해 필요한 보트 개수

1. 정렬
2. 큰 놈부터
    2-1. 큰 놈만으로 꽉 참 -> 보내기
    2-2. 큰 놈으로 안 참 -> 앞 놈 이랑 합쳐서 보낼 수 있는지 체크하기
    
=> 해냈당! 근데 제한이 2명이었어서 다행이지, 더 많았으면 좀 더 복잡해졌을 것 같다
*/
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    int left = 0;
    int right = people.size() -1;
    
    sort(people.begin(), people.end());

    while(left <= right){
        int total = people[right];
        
        if(total + people[left] <= limit){
            left++;
        }
        right--;
        
        answer++;
    }
    
    return answer;
}