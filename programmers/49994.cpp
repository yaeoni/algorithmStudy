/*
- 처음 걸어본 길의 "길이" 구하기
- 좌표평면 경계 넘어가면 무시 / (10, 10)의 크기 => 좌표로 치니까 (11, 11), 시작점은 (5,5)
- 그냥 좌표 자체를 들어갔다 로 판단했더니 돌아오는게 판단이 안된다. // 각 좌표별 상하좌우 값을 가지게 할수도 없는 노릇. 


-> 흠 흠 흠 흠 고민중,, 각 좌표별로 두는 쪽인 것 같은데 c++에선 어떻게 표현할까 
    배열의 요소가 4개의 배열로 2차원 벡터의 요소가 벡터

=> 4차원 배열을 활용!!! from좌표, to좌표로,,
=> "간선 자체의 방문여부" 체크
=> 나는 x, y를 x를 row, y를 col로 해서 쓰는데 딴 사람들은 반대로하네 ! ?
*/
#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    // from x,y / to x,y
    // 간선 체크(양방향 다 체크해야한다)
    int board[11][11][11][11];

    int x = 5;
    int y = 5;

    for(auto dir : dirs){
        if(dir == 'U'){
            if(x+1 < 11){
                if(board[x][y][x+1][y] != 1){
                    // 양방향 체크
                    board[x][y][x+1][y] = 1; 
                    board[x+1][y][x][y] = 1;
                    answer++;
                }
                x++;
            }
        }
        
        else if(dir == 'D'){
            if(x-1 >= 0 ){
                if(board[x][y][x-1][y] != 1){
                    // 양방향 체크
                    board[x][y][x-1][y] = 1; 
                    board[x-1][y][x][y] = 1; 
                    answer++;
                }
                x--;
            }
        }
       
        else if(dir == 'R'){
            if(y+1 < 11){
                if(board[x][y][x][y+1] != 1){
                    // 양방향 체크
                    board[x][y][x][y+1] = 1; 
                    board[x][y+1][x][y] = 1;
                    answer++;
                }
                y++;
            }
        }
        else{
            if(y-1 >= 0){
                if(board[x][y][x][y-1] != 1){
                    // 양방향 체크
                    board[x][y][x][y-1] = 1; 
                    board[x][y-1][x][y] = 1;
                    answer++;
                }
                y--;
            }
        }
    }
    
    return answer;
}