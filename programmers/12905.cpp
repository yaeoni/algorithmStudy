/*
- bfs나 dfs를 써야하는데. 정사각형이라는 기준을 어떻게 잡아줘야하지?!
- 매 점마다 변 길이를 1씩 늘려가면서 만들 수 있는지 체크
=> 휴 다행스럽게도(?) 이 방법이 아니었따...

- DP (Dynamic Programming)
    : 반복되는 연산 줄이기 위한 방법(점화식 세우기)
    
- 배열을 돌면서, 해당 점이 1이라면 (왼, 왼위, 위) 중 최소값 + 1 로 갱신(+1은 변의 길이가 늘어났다는 뜻)
- 만약 최소값 중 0이었다면 해당점은 0+1 로 1 현상유지
*/
#include <iostream>
#include<vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[1000][1000] = { false,};

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    
    int r = board.size();
    int c = board[0].size();
    
    // 두번째 행부터 시작(out of index 방지)
    for(int i = 1 ; i < r ; i++){
        for(int j = 1 ; j < c ; j++){
            if(board[i][j] == 1){
                board[i][j] = 1 + min({board[i-1][j-1], board[i][j-1], board[i-1][j]});
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer*answer;
}