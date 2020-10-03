#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0 ; i < commands.size() ; i++){
        if(commands[i][0] > array.size() || commands[i][1] > array.size()) 
            continue;
        
        vector<int> temp;
        
        int start = commands[i][0]-1;
        int end = commands[i][1];
        int index = commands[i][2] -1;
        for( int j = start ; j < end ; j++){
            temp.push_back(array[j]);
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[index]);
    }
    return answer;
}
