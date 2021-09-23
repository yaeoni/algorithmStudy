/*
- 영문 대문자로 사전 초기화  
- 사전 속에 있는 가장 긴 문자열 찾기
- 없으면 추가하고 넣기
- 한글자씩 처리

- 사전 자체는 unordered_map 쓰면 될 것 같은데! => 오, 됐다 => 이게 최선인지는 사실. 모르겠다 ㅎ
- string "" 로 두고 += 로 계속 체크하는 방법이 있었네요!
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> um;
    
    
    // 사전 초기화
    int next = 27;
    
    for(int i = 0 ; i < 26 ; i++){
        char ch = 'A' + i;
        string temp(1, ch);
        um.insert(make_pair(temp, i+1));
    }
    
    unordered_map<string,int>::iterator it;
    
    
    for(int i = 0 ; i < msg.size() ; i++){
        // 한 글자 -> 언제나 존재하지.
        string inDict;
        inDict.push_back(msg[i]);
        int value = um[inDict];
        
        // 더 긴 글자가 존재하는가?
        unordered_map<string, int>::iterator it;
        
        while(true){
            string temp = inDict;
            temp.push_back(msg[i+1]);
           
            it = um.find(temp);
        
            if(it != um.end()){
                // 사전에 존재한다면, 출력값 바꾸기
                value = um[temp];
                inDict = temp;
                i++; // 입력글자 제거
            }else{
                // 사전에 추가 및 출력 후 break;
                answer.push_back(value);
                um.insert(make_pair(temp, next++));
                break;
            }
        }
        
    }
    
    return answer;
}