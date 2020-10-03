#include<iostream>
#define ALPHABETS 26
struct Trie{

    Trie* child[ALPHABETS];
    bool is_terminal;
   
    Trie(): is_terminal(false){
        memset(child,0,sizeof(child));
    }
    ~Trie(){
        for(int i =0; i <ALPHABETS ; i++){
            if(child[i]) delete child[i];
        }
    }

    void insert(char* str){
        //문자열의 끝에 도달했을 때
        if(str == NULL){
            is_terminal = true;
            return;
        }

        // 문자열에서 현재 문자 가져오기, child에 이미 존재하는지 확인
        int current = *str -'A';
        
        // 연결된 노드가 없는 경우 노드를 생성
        if(child[current] == NULL) child[current] = new Trie();

        // 다음 문자로 넘어감
        child[current]->insert(str+1);
    }

    bool find(char* str){

        if(*str = NULL){
            if(is_terminal) return true;
            return false;
        }

        int current = *str - 'A';
        if(child[current] == NULL) return false;
        return child[current]->find(str+1);
    }
}

