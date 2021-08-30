/*
- 서로 다른 옷 조합의 수 (의상의 이름, 의상의 종류) / 중복 없음
- unordered_map 으로 요소로 벡터를 넣을 수 있는 지 모르겠지만? -> 가능이었다.
- key:value로 만들어는 놨는데 조합을 어떻게 세웠드라 / 각각 하나씩도 괜찮음
- "수" 만 알아내면 되니까 각 개수 + 나올 수 있는 조합 개수 각각 곱하기 하면 된다.  => ㅋㅋ 아니당 ㅎ
- 하나를 입을수도, 두 개를 입을수도, 세 개를 입을수도 있으니까(모든 종류를 다 입는게 아녀)
    => 테케 1에서 시간초과가 난다. 이유가 뭘까요.,,
    => 애초에 combinations를 안써도. 숫자 자체로 곱해버려도 와 시발.ㄹㅇㅁ.ㄹㅁ.ㅇㅁ.ㄹ
    
[검색]
- 2개 1개 일때
 -> (2C1 +1(선택하지 않는 경우)) + (1C1 +1(선택하지 않는 경우))
 -> 둘 다 선택하지 않는 경우로 -1 을 빼줘야함.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    for(auto c: clothes){
        string kind = c[1];
        um[kind] += 1;
    }
    
    for(auto elem : um){
        answer *= elem.second +1;
    }
    /* set<s> 로 key값 모아놨었음
    set<string>::iterator iter;
    
    vector<string> key(s.begin(), s.end());
    
    for(int i = 1 ; i <= key.size() ; i++){
        vector<int> v(key.size()-i, 0);
        v.insert(v.end(), i, 1);

        //cout << i << "개" << endl;
        do
        {
            
            int temp = 1;
            for (int k = 0; k < key.size(); k++)
            {
                
                if(v[k]){
                    if(i == 1) answer += um[key[k]].size();
                    else{
                        temp *= um[key[k]].size();
                    }
                    //comb.push_back(key[k]);
                } 
            }
            if( i != 1) answer += temp;
           
            
        } while (next_permutation(v.begin(), v.end()));
    }
    */
    return answer - 1;
}