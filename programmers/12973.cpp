/*
1. 같은 알파벳 연속 2개 찾기 -> 제거
2. 앞뒤로(나머지) 이어 붙이기
3. 문자열 모두 제거하면 종료
4. 성공 여부 반환 함수 please

- 모두 소문자로 이루어짐 
- 100만 길이니까,, for 1번만 돌면 좋을텐데!

[나]
- "aa" ~ "zz" 를 모두 만들어두고 한번 돌 ㄸ ㅐ 다 돌게,, 
    -> 효율성 0 일거같음 
    -> 그래도 한 번 해보겠음 
    => 진짜 시간초과 / 테케에서도 시간초과나옴 ㅎ 우하하
    
=> 사실 이것도 그냥 인덱스로 비교하는게 더 빠르다..

[검색]
- STACK을 이용하자!
- 스택에 1글자씩 넣어주면서 top과 현재 글자 같으면 pop
- 글자가 홀수개면 짝지어 제거 불가! 
~~ 오홍 ~~ 
*/
#include <iostream>
#include<string>

using namespace std;

int solution(string origin)
{
    int answer = 0;
    
    string cand[] = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", "nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"} ;
    
    bool flag = true;
    
    string temp = origin;

    while(flag){
        // 끝까지 
        for(auto str : cand){
            // 찾았다면
            if(temp.find(str) != string::npos){
                int index = temp.find(str);
                temp = temp.substr(0, index) +temp.substr(index+2, temp.size());
            }
        }
        // 다 돌았는데 똑같다면
        if( origin == temp) flag = false;
        origin = temp;
    }
    
    if(temp.size() == 0) answer = 1;
    return answer;
}
 
/* 효율성 버전
[검색]
- STACK을 이용하자!
- 스택에 1글자씩 넣어주면서 top과 현재 글자 같으면 pop
- 글자가 홀수개면 짝지어 제거 불가! 
~~ 오홍 ~~ 너무 쉬웠네,,ㅎ
*/
#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string origin)
{
    int answer = 0;

    stack<char> s;
    
    for(int i = 0 ; i < origin.size() ; i++){
        if(s.empty() || s.top() != origin[i]) s.push(origin[i]);
        else s.pop();
    }
    
    if(s.size()==0) answer = 1;
    return answer;
}