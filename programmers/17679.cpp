/*
- 2*2가 지워지고 / 위에있는게 아래로 떨어지고

1. map(v) 만들어주기
2. 하나씩 돌면서 2*2를 찾아주면되는데 이후에 "아래로 떨어진다는게" 감이 잘 안잡힌다.
3. 노가다로 해주면 효율성 0 점인데,, => 허거덩~ 그냥 하는거였나바 ㅎ

- board 그대로 사용하면 된다(이차원배열적 접근가능)
    =>그렇게 어렵진 않았는데, 그냥 많이 쫄아서,, ㅠㅠ속상
*/
#include <string>
#include <vector>

#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    bool flag = true;
    
    while(flag){
        bool arr[30][30] = {false, };
        flag = false;        
        
        // 주변 4 블록 검사(맨 끝은 안해도 된다)-> 2중 for문
        for(int i = 0 ; i < m-1 ; i++){
            for(int j = 0 ; j < n-1 ; j++){
                
                if(board[i][j]== ' ') continue;
                
                char target = board[i][j];
                
                if(target == board[i][j+1] && target == board[i+1][j] && target == board[i+1][j+1]){
                    arr[i][j] = true;
                    arr[i][j+1] = true;
                    arr[i+1][j] = true;
                    arr[i+1][j+1] = true;
                    flag = true; // 또 board를 검사해야한다!
                }
            }
        }
        
        // 아래로 내려주기
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(arr[i][j]==true){ // true , 지워진 블록이라면 아래로 내려주기
                    answer++;
                    for(int k = i-1;  k >=0 ; k--){ // 위에있는 것들 싹 내려주기
                        board[k+1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                    
                }
            }
        }
        
    }
    return answer;
}