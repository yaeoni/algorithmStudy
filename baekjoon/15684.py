import sys

n, m, h = map(int, sys.stdin.readline().split())

# 사다리의 초기화
ladder = [ [0]*n for _ in range(h)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    ladder[a-1][b-1] = 1

def isSame():
    global ladder

    for i in range(n):
        x, y = 0, i # 출발 좌표
        endPoint = y # 최종적으로 같은 좌표로 도착을 해야함.

        while(True):
            # 가로줄이 h+1 이다 = 끝점이다.
            if x == h:
                break
            # 오른쪽 사다리 있는 지 확인 -> 있으면 옮겨가기 / 범위 체크
            if( y+1 < n and ladder[x][y]==1):
                y = y + 1
            # 왼쪽에 사다리가 있는 지 확인
            elif( y-1 >=0 and ladder[x][y-1]==1):
                y = y - 1

            # 내려가기
            x, y = x+1, y
        
        if y != endPoint:
            return False

    return True
# 최대 3개까지 이므로
ans = 4

# 후보가 될 사다리 조합
candidate = []

for i in range(h):
    for j in range(n):
        if(ladder[i][j] == 0):
            # 양 옆에 사다리가 있는지, 없으면 후보군에 넣어주기 / 범위 확인
            if(j==0):
                if(j+1<n and ladder[i][j+1]==0):
                    candidate.append([i,j])
        
            elif(j==n-1):
                if(j-1>=0 and ladder[i][j-1]==0):
                    candidate.append([i,j])
            else:
                if(ladder[i][j-1]==0 and ladder[i][j+1]==0):
                    candidate.append([i,j])

def dfs(added, num):
    global ans

    # 넣은 사다리의 개수가 4개넘어가면 더 탐색할 필요 없음.
    if added >= ans:
        return
    
    if isSame():
        ans = added
        return

    # 여기서부터 사다리를 놓는다. 
    # 가능한 사다리 조합을 만들어야하기 때문에 num+1 부터 가는거! (연속적이지 않을 조건을 이용하면 된다.)
    for idx in range(num+1, len(candidate)):
        i, j = candidate[idx]

        if(j==0):
            if(j+1<n and ladder[i][j+1]==0):
                ladder[i][j]=1
                dfs(added+1, idx)
                ladder[i][j]=0
        elif(j==n-1):
            if(j-1>=0 and ladder[i][j-1]==0):
                ladder[i][j]=1
                dfs(added+1, idx)
                ladder[i][j]=0
        else:
            if(ladder[i][j-1]==0 and ladder[i][j+1]==0):
                ladder[i][j]=1
                dfs(added+1, idx)   
                ladder[i][j]=0


dfs(0, -1)
print(ans if ans <4 else -1)

