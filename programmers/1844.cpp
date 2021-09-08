/*
- bfs, dfs 해서 최단거리 구해야함 
- 지나온 거리를 기억하면서 -> 도착 지점에 도달했을 때 해당 거리를 저장해야한다.
- 둘 다 써보자!
=> 전형적인 문제인데 왜 못하니,,, 도르륵,, 에횽

- (프로그래머스) c++ 에선 2차원 전역변수 쓸거면 함수 내에서 초기화 해주자 ,, !!

- "최단거리"를 구할 때는 bfs !
- dfs는 모든 노드를 방문
- bfs는 현재 정점에 연결된 가까운 점들부터 탐색

=> 좀 더 분발하자 ! visited를 그냥 지나갔다 만의 용도가 아니라 가중치를 주면서 활용할 수 있는 값으로 쓰기!
*/

/* dfs 버전 */
#include<vector>
#include<iostream>
using namespace std;

// 상 하 좌 우 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

// dfs에서도 visited 여부는 꼭 필요한데, 여기서는 최단 거리를 판단하기 위해서! 활용
int visited[100][100];

int n; // row
int m; // col


void dfs(int x, int y, const vector<vector<int> > maps, int depth){
    visited[x][y] = depth;
    
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && maps[nx][ny] == 1 && visited[nx][ny] > depth+1){
        
            dfs(nx, ny, maps, depth+1);
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    n = maps.size();
    m = maps[0].size();
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            visited[i][j] = 10001;
        }
    }
    
    dfs(0,0, maps, 1);
    
    if(visited[n-1][m-1] == 10001) return -1;
    return visited[n-1][m-1];
}

/* bfs 버전 */
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

// 상 하 좌 우 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

// dfs에서도 visited 여부는 꼭 필요한데, 여기서는 최단 거리를 판단하기 위해서! 활용
int visited[100][100];

int n; // row
int m; // col


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    n = maps.size();
    m = maps[0].size();
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            visited[i][j] = -1;
        }
    }
    
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    visited[0][0] = 1; // 시작점 1칸 갔다 표시
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위 내에 있고, 갈 수 있고, 아직 방문을 안했다면
            if(0 <= nx && nx < n && 0 <= ny && ny < m && maps[nx][ny] == 1 && visited[nx][ny] == -1){
                visited[nx][ny] = visited[x][y] +1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    return visited[n-1][m-1];
}