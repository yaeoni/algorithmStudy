"""
- dfs : 모든 점에 대해 다 탐색(깊이 우선으로)하므로 비효율적 -> visited를 10001에서 1씩 깎아가면서, 다음 점이 해당 visited보다 크다면 진행(1씩 더하면서)
- bfs : 출발점과 근교에 있는 점부터 탐색 -> visited를 1씩 늘려가면서

- 약간 bfs, dfs의 최단거리 구하는 효율성의 차이 감을 잘 못잡았는데,
dfs는 모든 자식 다 돌고나서 최단거리를 판단해야하지만(하나의 자식 가면 그대로 아래로 죽 이니까)
bfs는 같은 레벨에 있는 점들 다 돌면서, 목적지를 만나면 그대로 끝내버리면 되기 때문에 좀 더 효율적.
"""
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def solution(maps):
    answer = 0
    
    q = deque()
    
    n = len(maps)
    m = len(maps[0])
    
    visited = [[-1]*m for _ in range(n)]
    
    visited[0][0] = 1
    q.append((0,0))

    while(len(q)):
        x, y = q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if(0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1 and visited[nx][ny] == -1):
                visited[nx][ny] = visited[x][y] + 1
                q.append((nx, ny))
    return visited[n-1][m-1]