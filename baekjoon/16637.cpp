/*
- 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값
- 정답은 2^31보다 작고, -2^31보다 크다. -> int가 2^31까지 나타낼 수 있음

- 수식에 포함된 정수는 모두 0보다 크거나 같고, 9보다 작거나 같다(오)
- 항상 올바른 수식
- 연산자는 +, -, * 중 하나
- 수식 길이 N(1 ≤ N ≤ 19) & 0.5초

- 연산자는 +, -, * 중 하나

- 연산자 우선순위는 모두 동일 (오) => 아 이러면 직접 괄호를 넣어서 계싼하면 안된다. => 스택을 이용해서!
    => 괄호가 생긴다면? -> 해당 부분 도려내고 괄호부분 계산해서 넣기(?)
- 단, 괄호 안에는 연산자가 하나(오)
- 추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.
- 단 중첩 괄호 사용 불가

=> 연산자 위치는 항상 홀수 index를 가지겠군!
    => 수식 속에 연산자 개수는 N/2 

[내 생각]
=> 먼저 연산할 연산자의 경우의 수(index)를 따지고 싶은데! / 중첩괄호 X 이므로 양 옆 연산자는 포함하면 안된다.
=> 연산자 개수 
    - 1~2개 -> 최대 1개 괄호 / 단 1개일땐 그냥 리턴 시켜버려
    - 3~4개 -> 최대 2개 괄호 가능
    - 5~6개 -> 최대 3개 괄호 가능
==> 이러면 안됐따. 막막의 끝이었따. ㅎ ㅎ ㅠ 

[막막,,검색 ㄱ]
- 2 가지의 경우의 수로 계산 가능(DFS-재귀) -> 현재위치와 계산 값 기억
    1. 괄호로 묶지 않고 바로 다음 숫자와 연산 = 이전 + 현재
    2. 괄호로 묶고 연산 -> 다다음 숫자와 연산  = 이전 + 괄호 수식
        => 마지막 연산자의 경우엔 괄호로 묶을 수 없음
        => 현재 값과 다음 괄호의 값 게산

- dfs를 이용해 이전값을 물고 연산자를 체크해야한다는게 쉽지 않았다.
    - 좌표 상 dfs/bfs만 해서 그랬겠지 ㅠㅜㅠ
    - 언젠간 내 머리로 잘 풀 수 있는 날을 기다리며,,,ㅜ,ㅜ 
*/
#include <iostream>
#include <algorithm>
#include <climits> // climits 써야 컴파일 에러 안남!!!
using namespace std;

int N;
string command;

int result = INT_MIN;

// 계산하는 함수
int calculate(int a, int b, char op){
    if(op == '+') return a+b;
    else if(op == '-') return a-b;
    else return a*b;
}

// dfs 재귀함수(cur :이전 계산값)
void solution(int idx, int cur){

    // 계산 완료
    if(idx >= N){
        result = max(result, cur);
        return;
    } 
    
    // 맨 처음에는 0에다 더해야줘함(+)
    // 이후엔 이전 [*, +, -] 값(or 괄호) 이므로 계산값 이전의 연산자 불러와야함
    char op = idx == 0 ? '+' : command[idx-1];

    // 괄호 X 계산(이전값 - 현재 숫자)
    int noBracket = calculate(cur, command[idx] - '0', op);
    solution(idx+2, noBracket);

    // 괄호 계산(이전값 - 괄호)
    // 뒤에 숫자가 더 있어야지 괄호 묶을 수 있다.
    if(idx < N-2){
        int bracket = calculate(command[idx]- '0', command[idx+2] - '0', command[idx+1]); // 괄호 계산
        solution(idx+4, calculate(cur, bracket, op)); // 이전값과 괄호를 연산해서 넣어줌.
    } 

}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> command;

    solution(0,0);

    cout << result << "\n";
    return 0;
}