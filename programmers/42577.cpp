/*
- 접두어인 경우에 false
- 정렬하고(그럼 길이 짧은것들이 앞에 올테니까)
- 중복 데이터는 없으니까 하나씩 넣으면서 비교하기
- 실패 테케는 뭘까..? / 시간초과도 뜬다. -> map으로 find하자.

- 옛날에는 트라이는 활용하긴했는데.
- 실패도 있고 , 시간초과도 여전히 있꼬! 

[검색]
- 모든 것 단순비교,, 나도 이렇게했는데 왜 틀렸을꼬?! 를 모르겠다.
- 야야야ㅑㅇ,, 접두어니까 앞에 있는거로 잡아야지,,, 미친.. substr써야지..
    -> 접두어 처리하니까 시간초과가 난다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> p) {
    bool answer = true;
    
    sort(p.begin(), p.end()); // 사전순 정렬이 되므로 인접원소만 비교하면되게된다.

    /* 기존 코드 (모두 비교)
    for(string temp: p){
        for(string comp: p){
            if(temp == comp) continue;
            
            if(comp == temp.substr(0, comp.size())){
                return false;
            }
        }
    }
    */
    
    // string의 sort특성(사전순 정렬) 활용한 방식,,! 요까지는 생각 못했네! 
    for(int i = 0 ; i < p.size()-1 ; i++){
        if(p[i] == p[i+1].substr(0, p[i].size()))
            return false;
    }
    
    return answer;
}