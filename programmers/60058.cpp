#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

// c++ -> 안에 스트링 바꿀거 아니면 const string& 와 같은 레퍼런스 타입을 사용하자!
bool isRight(string p){
    stack<char> s;
    
    for(int i = 0 ; i < p.size() ; i++){
        if(p[i] == '('){
            s.push(p[i]);
        }else{
            if(s.empty()){
                return false;
            }
            s.pop();
            
        }
    }
    if(!s.empty()){
        return false;
    }
    
    return true;
}

string makeRight(string p){
    string result = "";
    
    stack<char> s;
    
    int leftParen = 0;
    int rightParen = 0;
    int idx = 0;
    
    if (p.size() == 0) return "";
    
    for(int i = 0 ; i < p.size() ; i++){
        if(p[i]=='(') leftParen++;
        else rightParen++;
        
        if(leftParen == rightParen) {
            idx = i;
            break;
        }
    }
    
    // 1, 2
    string u = p.substr(0, idx+1);
    string v = p.substr(idx+1, p.size());
    
    // 3 
    if(isRight(u)){
        // 3-1
        result = u + makeRight(v);
    // 4
    }else{
        string temp = "(";
        temp += makeRight(v);
        temp += ")";
        
        for(int j = 1 ; j < u.size()-1 ; j++){
            if(u[j]=='(') temp += ")";
            else temp += "(";
        }
        return temp;
    }
    
    
    return result;
    
}

string solution(string p) {
    string answer = "";
    bool ret;
    
    ret = isRight(p);
    
    if(ret == true){
        return p;
    }else{
        //올바르게만들기유
        answer = makeRight(p);
        return answer;
    }
    
    return p;
}