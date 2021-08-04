/*
- 이전에 각 손님들이 주문할 때 가장 많이 함께 주문한 단품메뉴들을 코스요리 메뉴로 구성
- 최소 2가지 이상의 단품메뉴 /  최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만
- 리턴도 오름차순 기준으로

[생각]
1. 하나의 order에 대해 가능한 단품메뉴 조합(next_permutation 이용,, )로 dict
    -> 굳이 permutation을 써야하는가,, 어차피 오름차순으로 되어있을텐데
    -> 요소 자체가 오름차순으로 되어있으니까 orders를 정렬한다면? -> 그래도 조합 요소를 뽑아내는거엔 다름 없음
    -> 순열 생각했는데 그냥 조합 생각하기 !(애초에 값 자체는 정렬 되어있으니까)
    -> 기억해야하는 것 = 몇 번 주문 되었는가? , 조합이 무엇인가
2. 개수 세기 (2개이상인 것 체크할 거임)
3. 요구된 개수에 맞으면 result에 push
4. 오름차순 정렬

[검색]
- "가장 많이 함께 주문된 것!"
- 예를들어 "AD"가 4번, "AC"가 2번 주문됐으면 4번 주문된 "AD"를 리턴하라는거네 ,,!!! 막!!
*** 문제 이해가 덜 된 거였음,, 무하하 ****

- 애초에 주어진 course의 개수만큼만 조합 돌려도 되는거,, !<!<! 
    = 조합의 개수를 정해놓고 돌리자
- 후 마음을 다잡고 다시하자..


-> 얘는 따라 쳤다 !!!! 거의,,, 담에는 풀어봅시다,,
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool comp(pair<string, int> &a, pair<string, int> &b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}
vector<string> solution(vector<string> o, vector<int> c) {
    vector<string> answer;
   
    //조합 
    sort(o.begin(), o.end());
    for(int count: c){
        map<string, int> m;
        
        for(string data: o){

            vector<int> v;
            if(int(data.size()) >= count){

                for (int k = 0; k < data.size() - count; k++)
                    v.push_back(0);
                for (int k = 0; k < count; k++)
                    v.push_back(1);
                
                do{
                    string comb = "";
                    
                    for(int idx = 0 ; idx < v.size() ; idx++){
                        if(v[idx] == 1) comb += data[idx];
                    }
                    
                    sort(comb.begin(), comb.end());
                    m[comb] += 1;

                }while(next_permutation(v.begin(), v.end()));
            }
        }
        
        // map 에서는 개수별 정렬이 불가 하므로 vector로 옮겨서 한다
        vector<pair<string, int>> order(m.begin(), m.end());
        sort(order.begin(), order.end(), comp);
        
        // 코스 개수 만큼 가장 많이 나타난(주문한) 메뉴 넣기
        int max;
        if(!order.empty()){

            max = order[0].second;
            // 1번 이상 주문 되어야 하므로 !
            if(max!= 1){
                for(auto m: order){
                    if(max == m.second){
                        answer.push_back(m.first);
                    }
                }
            }
            
        }
        
    }
    sort(answer.begin(), answer.end());
    return answer;
}