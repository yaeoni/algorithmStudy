#include <string>
#include <vector>
#include <bitset>

#include <iostream>
#define MAX 16

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0 ; i < n ; i++){
      
        int num = arr1[i] | arr2[i];
        string one = bitset<MAX>(num).to_string().erase(0, MAX-n);
        
        string temp;
        
        for(int j = 0 ; j < one.length(); j++){
            if(one[j] == '1') temp += '#';
            else temp += ' ';
        }
        
            answer.push_back(temp);
    }
    return answer;
}
