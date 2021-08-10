/*
- 거리두기 확인하기 (DFS)
- 각 대기실 별로 2차원 배열,, 파싱부터 필요하다
- 응시자 자리(P) / 빈 테이블(O) / 파티션(X)

[나]
- 맨헤튼 거리부터 체크 / 해당하는 범위가 있을거아녀?
- 맨헤튼 거리에 해당하는 부분을 다 확인한다.
- 배열이 5*5니까,, 5*5*12 정도 확인하는거지 괜찮지않나!?
    => 하나하나 다 탐색하려했는데, segmentation fault에 가로막혔다.
    => 왜 참조는 되는데 탐색은 안될까,, 속상ㅎㅏ고 힘빠져...
    
[검색] / DFS, BFS 그래프 탐색 문제
- 모든 P에 대해 깊이 2를 초과하지 않는 선에서 탐색 진행 (상,하,좌,우로 검사하되 깊이 2가되면 끝내버리는거지,, 오오!)
- 그 내부에서 P를 마주칠 경우는 거리두기 지키지 않은 것.
- 파티션 X의 의미 = 탐색할 수 없는 지점

=> 오 ㅏ ,, 주어진게 대기실의 배열이니까 매번 visited는 초기화를 시켜줘야지,,, ㅋ  ㅋㅋㅋ맞네,,
*/
#include <iostream>

#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool visited[5][5];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool flag;

void dfs(int x, int y, vector<string>& place, int deep){
    for(int i = 0 ; i < 4 ; i++){
        
        if(deep == 2 || !flag) return;
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        /*
        if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && !visited[nx][ny] && place[nx][ny] != 'X'){
            if(place[nx][ny]=='P'){
                flag = false;
                return;
            }else{
                visited[nx][ny]=true;
                dfs(nx, ny, place, deep+1);
            }
        }
        */
        
        // 이미 검사했거나, X가 위치하면 검사하지 않는다.
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny] || place[nx][ny] == 'X') continue;
        
        if(place[nx][ny] == 'P'){
            flag = false;
            return;
        }else{
            visited[nx][ny] = true;
            dfs(nx, ny, place, deep+1);
        }
        
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto place : places){
        memset(visited, false, sizeof(visited));
        flag = true;
        
        for(int i = 0 ; i < 5 ; i++){
            for(int j = 0 ; j < 5 ; j++){
                
                if(place[i][j] =='P' && visited[i][j] == false){
                    visited[i][j] = true;
                    // check 함수
                    dfs(i, j, place, 0);
                }
                if(!flag){
                    answer.push_back(0);
                    break;
                }
            }
            
            if(!flag) break;
        }
        
        if(flag) answer.push_back(1);
    }
    
    return answer;
}