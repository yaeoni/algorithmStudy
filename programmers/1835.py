/*
- 총 8명의 캐릭터
- 문자열 파싱하고 조합이나 순열 생각하는 문제같은데,,
- 모든 조건을 만족! 한다.. 이걸 어떻게 세워야하지? 아예 감이 안잡히는뎨!
- "나란히" 선다의 의미를 어떻게 생각해야할까? 모두 다 나란히 설 수도 있고 그런거면 모든 경우의 수를 어떻게 생각해야할까? -> 일렬로 선다고 조건에 주어져 있으니까 나란히 서는건 옆자리! 어차피 조건은 다 숫자로 주어지니까 상관 없음.

[검색!] 
1. 순열 구현 -> c++ algorithm 라이브러리 속 next_permutation(ans++)
2. 조건 찾기 -> 조건에 해당하지 않으면 ans--
 * 떨어진 거리가 0 이다 = 옆자리다 = (인덱스 차이 - 1) 필요!
 
[나]
- 코드를 보면 쉽다고 생각이 든다! 머리론 생각 못했지만... ㅠ ㅎ
  next_permutation을 알게된 것으로 좋았던걸로!
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isRight(char op, int interval, int num){
    if(op == '='){
       return interval == num; 
    } 
    else if(op == '<'){
        return interval < num;
    } 
    else if(op =='>'){
        return interval > num;
    } 
}

int solution(int n, vector<string> data) {
    int answer = 0;
    
    // 순열에 필요한 친구들 목록 -> 라이브러리 이용해 알아서 뒤섞인다.
    string friends = "ACFJMNRT";
    do{
        bool flag = true;
        for(string input: data){
            char ff = input[0];
            char sf = input[2];
            char op = input[3];
            int num = input[4] - '0'; // char형이기에 숫자로 만들기
                
            // 실제 간격
            int interval = friends.find(ff) - friends.find(sf);
            // 절대값 처리 & 주어진 num은 인덱스간 간격의 - 1 처리 필요
            interval = abs(interval) -1; 
            
            if(isRight(op, interval, num)) continue;
            // 주어진 조건에 부합하지 않는데 answer에 추가되면 안되므로 flag 처리 필요
            flag = false;
            break;
        }
        if(flag) answer++;
        
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}