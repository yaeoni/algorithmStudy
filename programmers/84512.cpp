/*
- 길이 5 이하 모든 단어(A, E, I, O, U) => 얘네로 만들 수 있는
- 단어가 몇번째 단어인가? 
- 실제 수학문제에서는 A시작, E시작 ... 얘네부터 체크했던것 같은데..=> 손으로 풀라해도 못푸는 ㅠ 
- 5글자까지 갔다가 돌아와야돼 
=>=> 그냥 사전순 문제를 어떻게 푸는지 모르겠ㄷㅏ !!

1. 규칙찾아 풀기 => 아놔 이거는,, 왜 자리수를 곱하는지도 모르겠고 그냥 짜증난다. 안해..안할래..
2. dfs로 문자열 찾을때까지 반복하기
*/
#include <string>
#include <vector>

#include <iostream>
using namespace std;

int count;
int result;
void dfs(vector<char> v, string word){
    char ary[5] = {'A', 'E', 'I', 'O', 'U'};
    
    if(v.size() != 0){
        count++;
        string s(v.begin(), v.end());
        if(s == word){
            result = count;
            return;
        }
    }
    
    if(v.size() == 5) return;
    
    for(auto c : ary){
        v.push_back(c);
        dfs(v, word);
        v.pop_back();
    }
}
int solution(string word) {
    int answer = 0;
    
    count = 0;
    result = 0;

    vector<char> v;
    
    dfs(v, word);
    
    return result;
}