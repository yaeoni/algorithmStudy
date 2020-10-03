#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(pair<double, int> a, pair<double, int> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> reached(N+1, 0);
    vector<int> notClear(N+1, 0);
     
    vector<pair<double, int> > rate;
    
    
    for(int i = 1 ; i <= N ;i++ ){
        for(int j = 0 ; j < stages.size() ; j++){
            if(i == stages[j]) notClear[i]++;
            if( i <= stages[j]) reached[i]++;
        }
    }
  
    
    
    for(int i = 1 ; i <= N ; i++){
        double failed = reached[i] == 0? 0 : (double)notClear[i]/reached[i];
        rate.push_back(make_pair(failed, i));
    }
    
    sort(rate.begin(), rate.end(), comp);
    
    for(auto &pair: rate){
        answer.push_back(pair.second);
    }
        
    return answer;
}
