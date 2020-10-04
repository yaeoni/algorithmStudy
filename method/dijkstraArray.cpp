#include <iostream>
#define INF 1000000

int a[5][5] = {
    {0, INF, 6, 3, INF},
    {3, 0, INF, INF, INF},
    {INF, INF, 0, 2, INF},
    {INF, 1, 1, 0, INF},
    {INF, 4, INF, 2, 0}
};

bool visited[5]; //방문한 노드
int d[5]; // 갱신될 최단경로 거리
int num = 5;

using namespace std;

//최조 거리 가지는 정점 반환
int getSmallIndex(){
    int min = INF;
    int index = 0;

    for(int i = 0; i < num ; i++ ){
        if(d[i] < min && !visited[i]){
            min = d[i];
            index = i;
        }
    }
    return index;

}

void dijkstra(int start){
    for(int i = 0; i < num ; i++){
        //시작 정점과 연결되어있는 정점 보기 및 업데이트
        d[i] = a[start][i];
    }
    visited[start] = true;

    for(int i = 0; i < num -2 ; i++){
        int current = getSmallIndex();
        visited[current] = true;
        for(int j = 0 ; j < num ; j++){

            if(!visited[i]){
                if(d[current] + a[current][j] < d[j])
                    d[j] = d[current] + a[current][j];
            }
        }
    }

}
int main(void){



}