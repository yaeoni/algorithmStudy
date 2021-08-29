/*
- 우선순위 큐를 이용해서 푸는 방법 -> 시간이 확연히 차이가 난다.
- C++ fill 함수 -> algorithm 라이브러리 사용 / 배열 특정 값으로 채워넣을 때 사용
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int INF = 500001;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 최소 경로
    vector<int> dist(N);
    fill(dist.begin(), dist.end(), INF);
    
    //인접 행렬 이용
    vector<pair<int, int>> adj[N];
    for(int i = 0 ; i < road.size() ; i++){
        int u = road[i][0]-1, v = road[i][1]-1, cost = road[i][2];
        
        adj[u].push_back(make_pair(v, cost));
        adj[v].push_back(make_pair(u, cost));
    }
    
    // 우선순위 큐 -> first기준으로 정렬이니까, 앞에 cost를 넣어줘야한다.
    priority_queue<pair<int, int>> pq;
    
    dist[0] = 0;
    pq.push(make_pair(0,0));
    
    while(!pq.empty()){
        int cost = pq.top().first; // res 중 가장 최소 값
        int now = pq.top().second;
        pq.pop();
        
        if(cost > dist[now]) continue;
        
        // 현재 위치와 연결되어 있는 얘들 중에 더 최소로 갈 수 있는게 있는지 체크
        for(int i = 0 ; i < adj[now].size() ; i++){
            int next = adj[now][i].first;
            int nextDist = cost + adj[now][i].second;
            
            if(nextDist < dist[next]){
                dist[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }
    
    for(auto v : dist){
        if(v <= K) answer++;
    }
    return answer;
}