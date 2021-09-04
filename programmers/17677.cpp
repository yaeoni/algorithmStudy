/*
- 1. 2 글자씩 끊어서 다중집합의 원소로 만들기
    - 영문자로 된 글자만 유효 / 공백,숫자,특수문자는 버림
    - 대문자 소문자 차이는 무시
    
- 교집 합집 구하는건 따로 뭐가 있대도 자르는거까지 해보겠움
- 다중 집합 -> 더 큰놈을 쫓아간다는거지 
[검색]
- 그냥 교집,합집 원래 알던 방식으로 직접 만들어줘도 상관없구나.
- 직접 함수를 사용하려면 서로 정렬을 먼저 해줘야함.
- string을 처음부터 소문자로 만드는법
    transform(str.begin(), str.end(), str.begin(), ::tolower);
*/
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> makeTokens(string str){
    vector<string> ret;
    
    for(int i = 1 ; i < str.size() ; i++){
        if( isalpha(str[i-1]) != 0 &&  isalpha(str[i]) != 0 ){
            string temp;
            temp += toupper(str[i-1]);
            temp += toupper(str[i]);
            ret.push_back(temp);
        }
        continue;
    }
    return ret;
}
int solution(string str1, string str2) {
    int answer = 0;
    int uni = 0, inter = 0;
    vector<string> one = makeTokens(str1);
    vector<string> two = makeTokens(str2);
    
    // 모두 공집합일 때 처리
    if(one.size() == 0 && two.size() == 0) return 65536;
    
    uni = one.size() + two.size();
    
    for(auto iter = one.begin() ; iter != one.end(); iter++){
        auto temp = find(two.begin(), two.end(), *iter);
        if(temp != two.end()){ // 중복 원소가 있다면
            inter++;
            two.erase(temp);
        }
    }
    //중복 원소 제거
    uni -= inter;
    
    if(uni == 0) return 65536;
    
    double ans = (double)inter / (double)uni;
    
    return ans *= 65536;
}