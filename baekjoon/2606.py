# 처음에 bfs, dfs가 안떠올라서 이렇게 짰는데,, 왜 틀렸다고 나오는걸까 딥빢치게!
# 그래프 -> bfs, dfs가 일반적 ! 근데 난 이제 이걸 그래프로 어떻게 집어 넣을지가 문제였다.
# 이것도 나름대로 bfs, dfs라고 볼 수 있는데 왜 와이 틀린거지.. 나 진짜 운다... 양방향 그래프로 안해서 그런가
# 악. 양방향 그래프로 안했기 때문에 틀린거였다. 어떤게 틀린 케이스인지 생각해봐야겠다.
n = int(input())
checked = [0]*(n+1)

m = int(input())

connect = {}

for _ in range(m):
    x, y = map(int, input().split())

    if x not in connect:
        connect[x] = [y]
    else:
        connect[x].append(y)

    if y not in connect:
        connect[y] = [x]
    else:
        connect[y].append(x)

# DFS 버전
def getCount(num):
    global ans

    checked[num]=1
    if num not in connect:
        return
    
    item = connect[num]

    for temp in item:
        if(checked[temp]==0):
            ans += 1
            getCount(temp)

getCount(1)
print(ans)

# BFS 버전(지나간 곳들 pop하면서 지나갈 곳 push 하기)
visit = []
queue = [1]

while queue:
    temp = queue.pop(0)
    if temp not in visit:
        visit.append(temp)
        queue.extend(connect[temp])

print(len(visit)-1)