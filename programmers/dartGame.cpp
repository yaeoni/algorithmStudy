#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    string num = "0123456789";
    
    for(int i = 0 ; i < dartResult.length() ;i++){
        //Number
        if((int)num.find(dartResult[i]) != -1){
            if( dartResult[i] == '1' && dartResult[i+1] == '0'){
                score.push_back(10);
                i++;
            }else{
                score.push_back(dartResult[i]-'0');
            }
        //Bonus
        }else if(dartResult[i] == 'D'){
            
           score.back() = pow(score.back(), 2);    
        }else if(dartResult[i] == 'T'){
            score.back() = pow(score.back(), 3);
        //Option
        }else if(dartResult[i] == '*'){
            score.back() = score.back()*2;
            score[score.size()-2] = score[score.size()-2]*2;
        }else if(dartResult[i] =='#'){
            score.back() = score.back()*(-1);
        }
        
    }
    for(int i = 0 ; i < score.size(); i++){
        answer += score[i];
    }
    
    return answer;
}