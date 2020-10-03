#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    string first = "12345";
    string second = "21232425";
    string third = "3311224455";
    int count[3];
    
    memset(count, 0, sizeof(count));
    
    string::iterator iterFirst = first.begin();
    string::iterator iterSecond = second.begin();
    string::iterator iterThird = third.begin();
    
    for(int i = 0 ; i < answers.size() ; i++){
        if(iterFirst == first.end())  iterFirst = first.begin();
        if(iterSecond == second.end()) iterSecond = second.begin();
        if(iterThird == third.end()) iterThird = third.begin();
        
        
        if(*(iterFirst++) - '0' == answers[i]) count[0]++;
        if(*(iterSecond++) - '0' == answers[i]) count[1]++;
        if(*(iterThird++) -'0' == answers[i]) count[2]++;
        
      
    }
    
    int max = 0 ; 
    for(int i = 0 ; i < 3 ; i++){
        if(max < count[i]) max = count[i];
    }
    for(int i = 0 ; i < 3; i++){
        if(max == count[i]) answer.push_back(i+1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
