#include <string>
#include <vector>
#include <iostream>
#include <cstring>

#define ALPHABETS 26

using namespace std;

struct Trie{
    
    bool isTerminal;
    Trie* child[ALPHABETS];
    
    Trie(){
        memset(child, 0, sizeof(child));
        isTerminal = false;
    }
    void insert(const char* str){
    
        if(*str == '\0'){
            isTerminal = true;
            return;
        }

        int current = *str - 'a';

        if(child[current] == NULL)
            child[current] = new Trie();
        
        child[current]->insert(str+1);
        
        
    }   

    bool find(const char* str){
        if(*str == '\0'){
            if(isTerminal) return true;
            return false;
        }
        
        int current = *str -'a';
        if(child[current] == NULL) return false;
        return child[current]->find(str+1);
    }

    
};


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    Trie* root = new Trie();
    for(int i = 0 ; i < completion.size() ; i++){
        const char* a= completion[i].c_str();
        root->insert(a);
    }

    for(int i = 0 ; i< participant.size() ; i++){
        const char* b = participant[i].c_str();
        if( !(root->find(b))){
            cout << b << endl;
            answer = b;
            break;
        }
        
    }

    return answer;
}

int main(void){
    
    vector<string> participant;
    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");

    vector<string> completion;
    completion.push_back("eden");
    completion.push_back("kiki");
    
    solution(participant, completion);
    
    return 0;

}