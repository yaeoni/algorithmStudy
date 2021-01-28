# 똑같이 따라 쓴건데도 왜 안될까.... 너무 화가난다...
# bfs로 해당 단지의 개수만 구한다는 느낌..! 그리고 지나온 곳은 0으로 바꿔줌으로서 다시 못 지나가게끔!
# 좀 더 연습이 많이 필요할 것 같다.
from collections import deque

n = int(input())

ary = [ list(map(int, input())) for _ in range(n)]
answer = []


# 위, 아래, 좌, 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x,y))
    count = 1

    # ** 지나온 곳을 0으로 만들어줘야 또 가지 않는다.
    ary[x][y] = 0

    while queue:
        item = queue.popleft()

        for i in range(4):
            nx = item[0] + dx[i]
            ny = item[1] + dy[i]

            # 왜 안에다 감싸면 틀릴까?
            if(0<= nx and nx < n and 0<=ny and ny <n):
                if(ary[nx][ny]==1):
                    ary[nx][ny]= 0
                    count += 1
                    queue.append((nx, ny))

    return count


for i in range(n):
    for j in range(n):
        # 주위에 해당하는 모든 1을 받아올 것이다.
        if(ary[i][j]==1):
            answer.append(bfs(i,j))


print(len(answer))
answer.sort()

for i in answer:
    print(i)