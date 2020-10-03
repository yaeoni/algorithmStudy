#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    
    int answer = 0;
    
    vector<int> count(31, 1);

    for(int i = 0 ; i< reserve.size() ; i++){
        count[reserve[i]] += 1;
    }
    for(int i = 0 ; i < lost.size(); i++){
        count[lost[i]] -= 1;
    }
    
    for(int i = 1 ; i <= n ; i++ ){
        if( i == 1 && count[i] == 0 ){
            if(count[i+1] > 1){
                count[i+1] -= 1;
                count[i] += 1;
            }
        }else if( i == n && count[i] == 0){
            if(count[i-1] > 1){
                count[i-1] -= 1;
                count[i] += 1;
            }
        }else{
           if(count[i] == 0){
               if(count[i-1] > 1){
                   count[i-1] -= 1;
                   count[i] += 1;
               }else if( count[i+1] > 1){
                   count[i+1] -= 1;
                    count[i] += 1;
               }
           }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(count[i] != 0) answer++;
    }
    return answer;
}
