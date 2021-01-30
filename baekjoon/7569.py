# 다차원 배열 -> 근데 시간이 초과가 나네 ㅠ 여기서 시간 초과를 안나게 하는 방법이 뭐가있을까?
# 입력 형식을 input 말고 sys로 해ㅇ야함!
import sys
from collections import deque

m, n, h = map(int, sys.stdin.readline().split())

ary = [ [list(map(int, sys.stdin.readline().split())) for _ in range(n)] for _ in range(h) ]

# 위 아래 좌 우 앞 뒤
dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dh = [0, 0, 0, 0, 1, -1]

queue = deque()


# 익은 토마토가 있는 부분을 queue에 삽입한다.
for i in range(h):
    for j in range(n):
        for k in range(m):
            if(ary[i][j][k]==1):
                queue.append((0, i, j, k))
            

day = -1

while queue:
    item = queue.popleft()

    if day < item[0]:
        day = item[0]
    
    for i in range(6):
        nh = item[1] + dh[i]
        nx = item[2] + dx[i]
        ny = item[3] + dy[i]

        # 범위 체크
        if( 0<= nh and nh < h):
            if(0<= nx and nx < n and 0<= ny and ny< m):
                # 익지 않은 토마토만 익게 만들 수 있음
                if(ary[nh][nx][ny] == 0):
                    ary[nh][nx][ny] = 1
                    queue.append((day+1, nh, nx, ny))


for i in range(h):
    for j in range(n):
        for k in range(m):
            if(ary[i][j][k]==0):
                print(-1)
                sys.exit()

print(day)
