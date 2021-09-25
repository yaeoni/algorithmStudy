/*
- 괄호 올바르게,,? 이것은 기본 of 기본 of 스택,,,?
*/
#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{

    stack<char> stack;
    
    for(auto c : s){
        if(c == ')'){
            if(stack.empty()) return false;            
            stack.pop();
        }else{
            stack.push(c);
        }
    }

    if(stack.empty()) return true;
    return false;
}