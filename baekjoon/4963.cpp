#include <iostream>
#include <queue>

using namespace std;

int map[51][51];

// 1인 부분의 땅은 visited 표기
bool visited[51][51];

int width, height;
int count;

//주변 8군데를 탐색하기 위함 / 우 하 좌 상 우상 우하 좌상 좌하
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool isPossible(int row, int col){
    //범위를 넘어갔을 때
    if( row < 0 || row => height) return false
    if( col < 0 || col => width ) return false

    return true;

}

void bfs(int row, int col){
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    
    count++;

    while(!q.empty){

        //pair queue이기 때문에 빼놓고 팝하기
        int x = q.front().first;
        int y = q.front().second;

        // 이 부분이 dfs 적 면모를 보이는 것 ! !! !
        q.pop();

        // 주위 8군데 확인
        for(int i = 0 ; i < 8 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( isPossible(nx, ny) && !visited[nx][ny] && map[nx][ny] == 1){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }


    }



}

int main(void){

    while(1){
        scanf("%d %d", &width, &height);
        if( width == 0 && height ==0) break;
        

        for(int i = 0 ; i < height ; i++){
            memset(map[i], 0, sizeof(map));
            memset(visited[i], 0, sizeof(visited));
        }

        for(int i = 0 ; i < height ; i++){
            for(int j = 0 ; j < width; j++)
                scanf("%d", &map[i][j]);
        }

        count = 0;
        for( int i = 0 ; i < height ; i++){
            for(int j = 0 ; j < width ; j++){

                // 아직 방문하지 않았고, 땅이라면 방문해서 그 주위를 완전 탐색 해본다.
                if(!visited[i][j] && map[i][j] == 1)
                    bfs(i,j);
            }
        }

    }
    printf("%d", count);
    return 0;
}