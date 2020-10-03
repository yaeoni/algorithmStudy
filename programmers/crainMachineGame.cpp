#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> getHeight(vector<vector<int>> board){
    vector<int> height;
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0 ; j < board.size(); j++){
            if(board[j][i] != 0 ){
                height.push_back(j);
                break;
            }  
        }
    }
    return height;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
   
    vector<int> bucket;
    vector<int> height = getHeight(board);
  
    for(int i = 0; i < moves.size(); i++){
        if( height[moves[i]-1] >= board.size()){
            continue;
        }
        
        int row = height[moves[i]-1]++;
        int item = board[row][moves[i]-1];
        
        if( bucket.empty()){
            bucket.push_back(item);
        }else{
            //버켓에 뭔가 들어있을 때
            if( item == bucket.back()){
                bucket.pop_back();
                answer += 2;
            }else{
                bucket.push_back(item);
            }
        }
        
    }
 
    return answer;
}
