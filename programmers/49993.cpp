/*
- 선행스킬 -> dict마냥 우선순위랑 같이 저장해놓을 수 없을까?
    => hashMap (?) // 순서가 정해져있으니까 굳이 맵을 써줄 필요는 없었음 ㅎ
- 스킬트리에서 매 스킬마다 선행스킬에 있는지 체크
- 해당 스킬(key)값의 자체 우선순위 값 기억

- 판단하게 될 스킬의 우선순위가 이 자체 우선순위 값보다 높으면 break
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    unordered_map<char, int> um;
    unordered_map<char, int>::iterator iter;
    
    for(int i = 0 ; i < skill.size() ; i++) um.insert(make_pair(skill[i], i));

    for(int j = 0 ; j < skill_trees.size() ; j++){
        string tree = skill_trees[j];
        
        // 낮을수록 우선순위가 높다.
        int priority = 0;
        bool flag = true;
        
        // 스킬 하나씩 돌면서 판단
        for(int k = 0 ; k < tree.size() ; k++){
            char current = tree[k];
            iter = um.find(current);
                           
            int temp;
            if (iter != um.end()) temp = iter->second;
            else continue;
            
            // 선행 스킬 트리에 존재하는 스킬이라면 '반드시' 순서대로 배워야함.
            if(priority == temp){
                priority++;
            }else{
                flag = false;
                break;
            }
        }
        if(flag) answer++;    
    }
    
    return answer;
}