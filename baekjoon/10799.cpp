/*
- 쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 공백없이 / 괄호 문자의 개수는 최대 100,000이다.
- 모든 인접한 쌍 ‘( ) ’는 반드시 레이저를 표현
- 잘려진 쇠막대기 조각의 총 개수를 구하자

[나]
- 이런건 보통 스택으로 처리를 하지 않나..
*/
#include <iostream>
#include <stack>
using namespace std;

string input;
stack<char> s;

int answer = 0;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> input;

    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] == '('){
            if(input[i+1] == ')'){
                // 레이저
                i += 1; 
                if(!s.empty()){
                    // 자를 막대기가 있을 때
                    answer += s.size(); // 1씩 늘려줌
                }

            }else{
                //쇠막대기 시작점
                s.push(input[i]);
            }
        }else if(input[i] == ')'){
            // 쇠막대기의 끝
            s.pop();
            answer++; // 끝나면 +1
        }
    }
    cout << answer << "\n";
    return 0;
}