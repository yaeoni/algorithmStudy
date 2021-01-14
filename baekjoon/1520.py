# dfs + DP 기법까지 응용하기! 
import sys
m, n = map(int, sys.stdin.readline().split())
a = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
 
# dp 를 0으로 초기화 하게 되면, 경로의 수가 0개인건지(도달을 못하는건지) 초기화로서의 0인지 모름
mem = [[-1]*n for _ in range(m)]

# x, y : 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 경로의 수를 리턴하는 dfs로 짠다.
def dfs(x,y):
    if(x == m-1 and y == n-1):
        return 1
    
    # memoization
    if(mem[x][y] != -1):
        return mem[x][y]
    else:
        # 0부터 시작해야 초기화되는거니깐
        mem[x][y] = 0 

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 상하좌우 에서의 경로 반환
            if(0 <= nx < m and 0 <= ny < n):
                if(a[nx][ny] < a[x][y]):
                    mem[x][y] += dfs(nx, ny)

    return mem[x][y]

print(dfs(0,0))
"""
# dfs 만으로 풀었을 때에는 시간 초과가 난다.
# M과 N은 각각 500이하의 자연수, 시간 제한 2초
import sys

m, n = map(int, sys.stdin.readline().split())
a = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]

# x, y : 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

answer = 0 

def dfs(x, y):
    global answer
    if(x == m-1 and y == n-1):
        answer +=1
        return
    else:
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]

            # 조건이 만족했을 때 dfs를 콜하면 된다. 이젠 기억 꼬꼬!
            if(0 <= nx < m and 0 <= ny < n):
                if(a[nx][ny] < a[x][y]):
                    dfs(nx, ny)
            
dfs(0,0)
print(answer)
"""