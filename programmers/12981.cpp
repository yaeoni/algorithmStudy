/*
- 마지막 문자로 시작하는 단어
- 나온 단어 X / 한글자 X => 대문자 처리는 ? ㄴ ㄴ 소문자만 있다.
- 자신의 몇번째 차례에 탈락하는가?
=> 난 이런거 나오면 항상 트라이를 생각하는데, 항상 첨부터 만들어 낸 적이 없네,,
=> 트라이도 나쁘지 않은데, 쉽게 map으로만 해도 풀린다.! 너무 어렵게 생각하진 말자구,, 트라이는 변형에서 강하다!
- 몇 번째 순서인가 ? 기억 -> map
- 나왔던 단어들 기억 -> Trie
- 마지막 글자는 이어서
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

const int ALPHA = 26;

class Trie{
    
public:
    bool final;
    Trie* child[ALPHA];

    Trie(){
        memset(child, 0, sizeof(child));
        final = false;
    } 

    ~Trie(){
        for(int i = 0 ; i < ALPHA ; i++) {
            if(child[i]) delete child[i];
        }
    }
    
    // string을 넣는다고 생각했을 때 
    void insert(const char* c){
        if((*c) == '\0') final = true;
        else{
            int index = (*c) - 'a';
            if(child[index] == 0){
                child[index] = new Trie();
            }
            child[index]->insert(c+1);
        }
    }
    
    bool isExist(const char* c){
        if(*c == '\0' && final == true){
            return true;
        }
        int index = (*c) - 'a';
        if(child[index]==0) return false;
        return child[index]->isExist(c+1);
    }
};

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    map<int, int> order;
    for(int i = 1 ; i <= n ; i++ ){
        order[i] = 0;
    }
    
    Trie* trie = new Trie();
    char last;
    
    for(int i = 0 ; i < words.size(); i++){
        int num = i%n + 1;
        order[num] += 1;
        
        const char* c = words[i].c_str();
        
        //cout << num << " " << words[i] << endl;
        
        if(words[i].size() < 2){
            answer.push_back(num);
            answer.push_back(order[num]);
            return answer;
        }
        if(i == 0){
            trie->insert(c);
            
            int size = words[i].size();
            last = c[size-1];
        }else{
            if(words[i][0] != last || trie->isExist(c) == true){
                //cout << "here" << endl;
                answer.push_back(num);
                answer.push_back(order[num]);
                return answer;
            }else{
                trie->insert(c);
                int size = words[i].size();
                last = c[size-1];
            }
            
        }
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

// map만을 이용한 version
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    map<string, int> m;
   if(words[0].size() <2) return {1,1};
    m[words[0]] = 1;
    for(int i = 1 ; i < words.size() ; i++){
        int prevSize = words[i-1].size();
        if(words[i].size() < 2 || m[words[i]] == 1 || (words[i-1][prevSize-1] != words[i][0])) {
            return {i%n+1, i/n+1};
        }else{
            m[words[i]] = 1;
        }
    }
    return {0,0};
}