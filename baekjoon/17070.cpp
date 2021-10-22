/*
- 행과 열의 번호는 1부터

- 파이프 회전
    - 가로 2가지
    - 세로 2가지
    - 대각선 3가지

- 가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다
- 파이프의 한쪽 끝을 (N, N)로 이동시키는 모든 방법의 개수 / 이동시킬 수 없는 경우에는 0

- bfs / dfs 이용하면 될 것 같은걸?!
- 현재 파이프 방향이 가로인지-세로인지-대각선인지 판단
    - 경우의 수 따라 빈칸 체크하고 밀기
    - 끝점을 기억해서 나아가면 될 것 같은데!

[나]
- bfs 로 한 번 풀어보겠습니다.
- 맨 끝 점을 기억
*/
#include <iostream>
#include <queue>

using namespace std;

int N;

int house[17][17];

typedef struct node{
    int row;
    int col;
}NODE;

int goRight(int row, int col){
    if(col + 1 <=N && house[row][col+1] != 1) return 1;
    return 0;
}

int goDown(int row, int col){
    if(row +1 <= N && house[row+1][col] != 1) return 1;
    return 0;
}

int goDiagonal(int row, int col){
    if(row+1 <= N && col+1<=N && house[row+1][col] != 1 && house[row][col+1] != 1 && house[row+1][col+1] != 1) return 1;
    return 0;
}
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    // 집 초기화
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> house[i][j];
        }
    }

    if(house[N][N]==1){
        cout << "0\n";
        return 0;
    }

    int answer = 0;
    // 가로(1), 세로(2), 대각선(3)
    queue<pair<int, NODE>> q;

    q.push({1,{1,2}});
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        int direction = t.first;
        int row = t.second.row;
        int col = t.second.col;  
 
        if(row == N && col == N){
            answer++;
            continue;
        }

        if(direction == 1){
            // 가로

            //오른쪽
            if(goRight(row, col)){
                q.push({1, {row, col+1}});
            }
            // 대각선
            if(goDiagonal(row, col)){
                q.push({3, {row+1, col+1}});
            }

        }else if(direction == 2){
            // 세로
            
            // 아래
            if(goDown(row, col)){
                q.push({2, {row+1, col}});
            }

            // 대각선
            if(goDiagonal(row, col)){
                q.push({3, {row+1, col+1}});
            }
        }else{
            // 대각선

            //오른쪽
            if(goRight(row, col)){
                q.push({1, {row, col+1}});
            }
            // 오른쪽 아래
            if(goDiagonal(row, col)){
                q.push({3, {row+1, col+1}});
            }
            // 아래
            if(goDown(row, col)){
                q.push({2, {row+1, col}});
            }
            
        }
    }

    cout << answer << "\n";
    return 0;
}