/*
- 릴레이션 속 모든 튜플에 대해 유일하게 식별
- 꼭 필요한 속성들로만(이미 그 조합으로 후보키가 됐으면 더 많은 조합(?)은 안댐)
- 후보키의 최대 개수 구하기

1. 후보키가 가능한 컬럼 조합을 다 구하고(next_permutataion인가로)
2. 후보키 가능한지 체크(row 돌면서, 해당 컬럼만 쏙 뽑아서 dict에 넣고 있으면 continue)
3. 후보키가 된 키 조합은 더이상 후보키 될 수 없음(if 후보키 in 컬럼조합 이면 conitnue)

* 유일성은 하겠는데, 최소성을 어떻게해야 가장 잘했다고 소문이 날까...
* 최소성은 이미 후보키가 된 column을 아예 빼버리면 될 것 같은데.
=> 컬럼의 개수를 이상하게 세서 그랬다. 그래도 82.1...
=> 최소성 판별할 때 요소 하나하나에 대해 체크를 해줘보자
=> 순서를 1개,2개,3개,, 로 늘려가는데 왜 안되는거야아

[검색] 미친ㄴㅋㅋ
“0123” 조합에 “13” 후보키가 포함되는 것을 거를 수 없다는 것이다. 1과 3이 붙어 있지 않아서 find로부터 걸리지 못했지만 사실 (0, 1, 2, 3) 열 조합에 (1, 3) 후보키의 조합인 1, 3 이 모두 들어있어서 후보키가 될 수 없다.
=> 문자열의 하나하나가 모두 포함될때! 로 해야함 find 하나로는 안돼
=> 미춌따 미춌따... ㅠㅠ 흑흑 그래도 풀어서 다행이다.

*/ 
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    vector<string> cand;
    
    int size = relation[0].size();
    string comb;
    for(int i = 0; i < size ; i++) comb += to_string(i);
    
    for(int i = 1 ; i <= comb.size() ; i++){
        vector<bool> v(comb.size()-i, false);
        v.insert(v.end(), i, true);
        //cout << i<<"개" << endl;
        
        do{
            string temp = "";
            for(int k = 0 ; k < comb.size() ; k++ ){
                if(v[k]) temp += comb[k];
            }
            
            // temp 가 후보키가 될 수 있는지 여기서 판별하기
            //cout << "후보키 : " << temp << endl;

            unordered_map<string, int> c;
            bool flag = true;
            
            for(int j = 0 ; j < relation.size(); j++){
                string s = "";
                for(auto t : temp){
                    s += relation[j][t-'0'];
                }
                
                //cout << "조합 : " << s << endl;
                if(c.count(s)){
                    //존재하면
                    //cout << "같은 키값 존재" << endl;
                    flag = false;
                    break;
                }else{
                    //존재하지 않으면
                    c[s] = 0;
                }
            }
            
            if(flag) {
                //cout << "후보키 : " << temp << endl;
                //cout << "최소성 판별 및 후보키 등록" << endl;
                for(auto c : cand){
                    //cout << "비교 " << c << " "<< temp << endl;
                    // temp(후보키 후보) 속에 c 의 요소가 모두 들어있다면. 최소성 만족X
                    int leng = 0;
                    for(auto t : temp){
                        if(c.find(t) != string::npos) leng++;
                    }
                    if(leng == c.size()){
                        flag = false;
                        break;
                    }
                    
                }
            }
            
            if(flag){
                //cout << "후보키 확정 " << temp << endl;
                cand.push_back(temp);
                answer++;
            }
            
        }while(next_permutation(v.begin(), v.end()));
    }
    
    
    return answer;
}