/*
- 입력 받는 것부터 막혔지만 뚜따뚜따
- END 나오면 하나의 스택 끝

[ERROR]
1. 숫자가 부족해서 연산을 수행할 수 없을 때
2. 0으로 나눴을 때 (DIV, MOD)
3. 연산 결과의 절댓값이 10^9를 넘어갈 때
    - 10^9 = 10억 -> long long을 쓰자.

[틀렸습니다] 
-> 아마 음수 10^9를 안해줘서 그런걸까?
-> SWP에서 에러 발견
-> input이나 NUM 뒤에 받는 숫자 long long 타입으로 수정
-> num 뒤 숫자들을 queue가 아니라 배열로 관리
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

// 절댓값 헤더는 헷갈리니까 두개 다 기억하고 넣어놓자.
#include <cstdlib>
#include <cmath>

using namespace std;

#define MAX 1000000000
string command; // input
vector<string> commands; // 프로그램 명령어
long long addNum; // NUM 뒤에 나오는 숫자
long long countNum; // 입력 숫자 개수
long long input; // input 숫자

int idx;
long long NUM[1001];

bool num(stack<long long>& s, long long num){
    s.push(num);
    return true;
}

bool pop(stack<long long>& s){
    if(s.empty()) return false;

    s.pop();
    return true;
}

bool inv(stack<long long>& s){
    if(s.empty()) return false;
    long long temp = s.top();
    s.pop();

    temp = -temp;
    s.push(temp);
    return true;
}

bool dup(stack<long long>& s){
    if(s.empty()) return false;
    long long temp = s.top();
    s.push(temp);
    return true;
}

bool swp(stack<long long>& s){
    if(s.size() < 2) return false;

    long long first = s.top();
    s.pop();

    long long second = s.top();
    s.pop();

    s.push(first);
    s.push(second);

    return true;
}

bool add(stack<long long>& s){
    if(s.size() < 2) return false;

    long long first = s.top();
    s.pop();

    long long second = s.top();
    s.pop();

    s.push(first+second);
    return true;
}

bool sub(stack<long long>& s){
    if(s.size() < 2) return false;

    long long first = s.top();
    s.pop();

    long long second = s.top();
    s.pop();

    s.push(second-first);
    return true;
}

bool mul(stack<long long>& s){
    if(s.size() < 2) return false;

    long long first = s.top();
    s.pop();

    long long second = s.top();
    s.pop();

    s.push(first*second);
    return true;
}

bool div(stack<long long>& s){
    if(s.size() < 2) return false;
    if(s.top() == 0) return false;

    long long first = s.top();
    s.pop();

    long long second = s.top();
    s.pop();

    long long result = abs(second) / abs(first);

    // 하나만 음수일 때 음수다.
    if(first * second < 0) result = -result;

    s.push(result);

    return true;
}

bool mod(stack<long long>& s){
    if(s.size() < 2) return false;
    if(s.top() == 0) return false;

    long long first = s.top();
    s.pop();

    long long second = s.top();
    s.pop();

    int result = abs(second) % abs(first);

    // 피제수가 음수면 음수다 -> 바꿔주기
    if(second < 0) result = -result;
    
    s.push(result);
    return true;
}


int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while(1){
        idx = 0;
        commands.clear();
        queue<long long> addNums; // NUM 뒤에 나오는 숫자(앞에서부터 연산해야해서 queue)

        // 명령어 저장
        while(1){
            cin >> command;

            if(command == "NUM"){
                cin >> addNum;
                NUM[idx++] = addNum;
            }else if(command == "QUIT"){
                return 0; // 프로그램 종료
            }else if(command == "END"){
                break;
            }

            commands.push_back(command);

        }

        // 입력 받고 프로그램 수행
        cin >> countNum;
        while(countNum--){

            bool flag = true; // 연산 성공적으로 수행여부 체크

            cin >> input; // 들어가는 숫자
            idx = 0;
            
            stack<long long> s; // 스택 선언
            s.push(input);

            // 에러 체크 필요
            for(int i = 0 ; i < commands.size() ; i++){
                string c = commands[i];

                if(c == "NUM"){
                    s.push(NUM[idx++]);
                }else if(c == "POP"){
                    flag = pop(s);
                }else if(c == "INV"){
                    flag = inv(s);
                }else if(c == "DUP"){
                    flag = dup(s);
                }else if(c == "SWP"){
                    flag = swp(s);
                }else if(c == "ADD"){
                    flag = add(s);
                }else if(c == "SUB"){
                    flag = sub(s);
                }else if(c == "MUL"){
                    flag = mul(s);
                }else if(c == "DIV"){
                    flag = div(s);
                }else if(c == "MOD"){
                    flag = mod(s);
                }
                if(!s.empty() && (s.top() > MAX || s.top() < -MAX)) flag = false;
                if(flag == false) break; 
            }
            // 에러 상황(연산에서 에러 / 연산값 절대값이 10^9 넘을 때 / 스택에 값이 1개가 아닐 때)
            if(flag == false || s.size() != 1 || s.top() > MAX || s.top() < -MAX) cout << "ERROR" << "\n";
            else cout << s.top() << "\n";
        }
        cout << "\n";
    }   
    
    return 0;
}