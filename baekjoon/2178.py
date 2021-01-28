# bfs는 queue에 어떤 조건을 가진 애들을 넣을지가 관건인것 같음. 그리고 지나온 곳은 체크해야지! !!!
# 현재 내가 있는 위치에 대한 이동의 경우는 다 넣었으니까 지나온 곳을 또 지날 필요가 하덜덜 없음.
from collections import deque

n, m =map(int, input().split())

miro = [list(map(int, list(input()))) for _ in range(n) ]
visited = [[0]*m for _ in range(n)]
# 위, 아래, 좌, 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

queue = deque()
queue.append((0,0,1))
visited[0][0] = 1
ans = []

while queue:
    cur = queue.popleft()

    if cur[0]== n-1 and cur[1] == m-1:
        print(cur[2])
        break
    
    for i in range(4):
        # 새로운 좌표 생성
        nx = cur[0]+dx[i]  
        ny = cur[1]+dy[i]
        nc = cur[2]+1

        if(0 <= nx < n and 0<= ny < m) and miro[nx][ny]==1 and visited[nx][ny] !=1:
            queue.append((nx, ny, nc))
            # 여기서 visited 표시를 안해줬던게 패인 요인 -> 여기서 지났따! 로 체크해야 queue에(지나갈 곳) 중복적으로 안들어감.
            visited[nx][ny]=1
