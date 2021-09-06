/*
- 이건 첨부터 모르겠어서 검색으로 배워갑시다!
- 회전에 의해 위치가 바뀐 숫자 중 가장 작은 숫자.

- 회전하는 것과 같이 주어진 인덱스 번호를 가지고 놀아야 하는 과정은 특별한 알고리즘과 자료구조가 사용되는 것이 아니기 때문에, 자기가 가장 편하다고 생각하는 방법으로 구현하는 것을 권장
    => 겁이나서 좀 ! 그렇다.
    
1. 숫자 오름차순으로 행렬이 채워짐 -> 이것 먼저 만들기
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    // 맵 initialize
    vector<vector<int>> board(rows, vector<int>(columns, 0));
    int num = 1;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            board[i][j] = num++;
        }
    }
    
    for(int i = 0 ; i < queries.size() ; i++){
        int x1 = queries[i][0] -1;
        int y1 = queries[i][1] -1;
        int x2 = queries[i][2] -1;
        int y2 = queries[i][3] -1;
        
        // max 값으로 우선 설정
        int minNum = rows * columns + 1;
        
        // 덮어씌워질 값 대비 => 회전 시작점 따라서 다르게 설정!
        int temp = board[x1][y1];
        
        for(int j = x1 ; j < x2 ; j++){
            minNum = min(minNum, board[j][y1]);
            board[j][y1] = board[j+1][y1];
        }
        
        for(int j = y1 ; j < y2 ; j++){
            minNum = min(minNum, board[x2][j]);
            board[x2][j] = board[x2][j+1];
        }
        
        
        for(int j = x2 ; j > x1 ; j--){
            minNum = min(minNum, board[j][y2]);
            board[j][y2] = board[j-1][y2];
        }
        
        
        for(int j = y2 ; j > y1 ; j--){
            minNum = min(minNum, board[x1][j]);
            board[x1][j] = board[x1][j-1];
        }
        
        board[x1][y1+1] = temp;
        
        answer.push_back(minNum);
    }
    return answer;
}