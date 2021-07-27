/*
- 1개 이상의 단위로 잘라 압축한 문자열 중 길이 가장 짧은 것 return
*/
#include <iostream>
#include <string>

using namespace std;
int solution(string s) {
    int answer = s.length();
    
    // 길이 1 인 경우에는 압축할 필요 없음.
    if(answer == 1){
        return answer;
    }
    
    // 문자열 자르는 단위 -> 반 이상으로는 압축할 수 없음
    // c++ 속 string.substr() 활용하기!, substr은 (start, offset)으로 활용해야함
    int unit = 1;
    
    while(unit < (s.length()/2)+1){      
        // initialize
        int compNum = 1;
        string modified, temp;
        string token = s.substr(0, unit);
        
        for(int i = unit ; i < s.length() ; i += unit ){
            temp = s.substr(i, unit);
            
            if(token == temp) compNum ++;
            else{
                if(compNum != 1) modified += to_string(compNum);
                modified += token;
                token = temp;
                compNum = 1;
            }
        }
        // 마지막 경우를 더해주는 것을 잘 캐치해야함!
        if(compNum != 1) modified += to_string(compNum);
        modified += temp;

        if(modified.length() < answer){
            answer = modified.length();
        }
        
        unit++;
    }

    return answer;
}