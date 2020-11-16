#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

#define NUM 10
using namespace std;

bool _answer = true;

class Trie{
public:
    bool isTerminal;
    Trie* child[NUM];
    
    Trie():isTerminal(false){
        memset(child, 0, sizeof(child));
    }
    
    ~Trie(){
        for(int i = 0 ; i < NUM ; i++){
            if(child[i]) delete child[i];
        }
    }
    
    void insert(const char* s){
        
        if(*s =='\0'){
            isTerminal = true;
            return;
        }
        
        int current = *s -'0';
        
        if(child[current]==NULL) child[current] = new Trie();
        
        if(child[current]->isTerminal){
            _answer = false;
            return;
        }
        child[current]->insert(s+1);
    }
    
};

bool solution(vector<string> phone_book) {
    
    bool answer = true;
    Trie* root = new Trie();
    
    
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0 ; i < phone_book.size() ; i ++ ){
        const char* input= phone_book[i].c_str();
        root->insert(input);
        if(_answer == false){
            answer = _answer;
            break;
        }
    }     
    
    return answer;
}