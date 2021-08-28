/*
- 1번 -> 각 마을로 배달
- K 시간 이후로 배달 가능 마을로만 주문.
- 그래프 표현하고 bfs나 dfs로 각 마을별 걸리는 '최소시간' 계산
- 주문 받을 수 있는 마을 개수 리턴

1. 그래프 표현 -> 이미 되어있음 (각 연결정보와 가중치
    이걸 이용해서 새롭게 만드는게 나을 것 같은데! / 배열로 만들자.
    * 거리가 2가지가 나올 수 있네
2. 최소 시간 계산(다익스트라겠지..?) -> 이건 정말 쳐봐야함
3. 최종 시간에서 K이하인 마을 개수 리턴

- 다익스트라나 다른 최소비용 구하는 방법을 잘 활용할 줄 알아야하는데 이번엔 검색으로 .. 
- 낼 파이썬으론 직접 하기 / 더 효율적인 최소비용 구하기(힙) 적용해보기
- 그리고 pair로도 많이 하네. 그것도 반영해보기?!
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int INF = 500001;
int found[50];

int choose(vector<int> distance,int N){
    int min = INF;
    int pos = -1;
    for(int i = 0 ; i < N ; i ++){
        if(distance[i] < min && found[i] != 1){
            min = distance[i];
            pos = i;
        }
    }
    return pos;   
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    INF = 500001;
    
    // 비용 벡터 초기화
    vector<int> dist(N, INF);
    // N*N 2차원 벡터 초기화
    vector<vector<int>> graph(N, vector<int>(N, INF));
    
    memset(found, 0, sizeof(found));
    
    // 그래프 초기화
    for(auto v : road){
        if(graph[v[0]-1][v[1]-1] < v[2]){
            continue;
        }
        graph[v[0]-1][v[1]-1] = v[2];
        graph[v[1]-1][v[0]-1] = v[2];
    }
    for(int i = 0 ; i < N ; i ++){
        graph[i][i] = 0;
    }
    
    // 시작 초기화
    for(int i = 0 ; i < N ; i++){
        dist[i] = graph[0][i];
        found[0] = 1;
    }
    
    for(int i = 0 ; i < N-1 ; i++){
        int u = choose(dist, N);
        found[u] = 1;
        
        for(int j = 0 ; j < N ; j++){
            if(found[j] != 1){
                if(dist[u] + graph[u][j] < dist[j]){
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }
    
    for(auto v : dist){
        if(v <= K) answer++;
    }
    return answer;
}