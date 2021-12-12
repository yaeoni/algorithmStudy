/*
- [] () {} 짝이 맞는지 / 맞으면 1, 아니면 0
- 3가지의 스택을 세워서 관리
- 가운데에 낑겨도 안된다.
*/
#include <stack>
using namespace std;

int solution(string &S) {
    stack<char> stack;
    
    for(auto s : S){
        if(s == '(' || s == '[' || s == '{'){
            stack.push(s);
        }else if(s == ')'){
            if(stack.top() != '(') return 0;
            else stack.pop();
        }else if(s == ']'){
            if(stack.top() != '[') return 0;
            else stack.pop();
        }else if(s == '}'){
            if(stack.top() != '{') return 0;
            else stack.pop();
        }
    }

    if(!stack.empty()) return 0;
    return 1;
}