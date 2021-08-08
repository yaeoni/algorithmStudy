/*
- 아이디어 자체는 생각했으나 dfs 구현까먹었다.. 히히
- programmers에서 c++ 전역변수는 함수 내에서 초기화 해주기!!! 
- c++ 버전 밖에 없군요
*/
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visited[100][100];

int width;
int height;


int dfs(int y, int x, const vector<vector<int>>& picture, int color){
    visited[y][x] = 1;
    
    int count = 1;
    
    for(int i = 0 ; i < 4 ; i++){
        int newY = y + dy[i];
        int newX = x + dx[i];
        
        if(newY < 0 || newX < 0 || newY >= height || newX >= width) continue;
        
        if(visited[newY][newX] != 1 && picture[newY][newX] == color){
            count += dfs(newY, newX, picture, color);
        }
    }
    
    return count;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    // 전역변수 visit 초기화
    memset(visited,0,sizeof(visited));
    
    width = n;
    height = m ;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(picture[i][j] != 0 && visited[i][j] != 1){
                number_of_area++;
                max_size_of_one_area = max( max_size_of_one_area, dfs(i, j, picture, picture[i][j]));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}