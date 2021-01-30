from collections import deque

m, n = map(int, input().split())

ary = [ list(map(int, input().split())) for _ in range(n)]

# 위, 아래, 좌, 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 익지 않은 토마토(0)에만 갈 수 있음 -> 1로 바꾸기
# (좌표, 지난 날짜)
queue = deque()

# 익은 토마토가 있는 곳을 push
for i in range(n):
    for j in range(m):
        if ary[i][j] == 1:
            queue.append((i,j,0))

day = -1

while queue:
    item = queue.popleft()
    #print(item)

    if day < item[2]:
        day = item[2]
    # 익었다는 표시 해주기
    for i in range(4):
        nx = item[0] + dx[i]
        ny = item[1] + dy[i]
        #print(nx, ny)
        # 범위 내에서
        if (0<=nx and nx<n and 0<=ny and ny<m):
            # 안익은 토마토가 있는 곳으로
            if(ary[nx][ny] == 0):
                #print("new", ary[nx][ny])
                ary[nx][ny] = 1
                queue.append((nx,ny, day+1))


for i in range(n):
    for j in range(m):
        if ary[i][j] == 0:
            day = -1
print(day)
