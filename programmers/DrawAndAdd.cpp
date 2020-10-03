#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cache[200];

vector<int> solution(vector<int> numbers) {
    memset(cache, -1, sizeof(cache));
    vector<int> answer;
    int result;
    
    for(int i = 0 ; i < numbers.size() ; i++){
        for(int j = i+1 ; j < numbers.size() ; j++){
                int result = numbers[i]+numbers[j];
                if(cache[result] == -1){
                    cache[result] = 1;
                    answer.push_back(result);
                }
            }   
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
