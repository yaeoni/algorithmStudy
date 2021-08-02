/*
- 중복 닉네임 허용
- (최종적으로)유저 아이디(구분자) - 닉네임 페어를 만들어서 result처리(unordered_map)
    -> enter : initialize, change : change
- for문을 두 번(아이디-닉넴 페어용 / 최종 result 처리용)
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, string> um;
    vector<pair<string,string>> order;
    
    // map initialize
    for(string value: record){
        vector<string> tokens = split(value, ' ');
        
        if(tokens[0] == "Enter"){
            um[tokens[1]] = tokens[2];
            order.push_back(make_pair(tokens[0], tokens[1]));
        }
        else if(tokens[0] == "Change"){
            um[tokens[1]] = tokens[2];
        }else{
            order.push_back(make_pair(tokens[0], tokens[1]));
        }
    }
    
  
    for(int i = 0 ; i < order.size() ; i++){
        string nickname = um[order[i].second];
        
        if(order[i].first == "Enter"){
            answer.push_back(nickname+"님이 들어왔습니다.");
        }else{
            answer.push_back(nickname+"님이 나갔습니다.");
        }
    }
    
    
    return answer;
}