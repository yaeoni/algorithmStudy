"""
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000) 
탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 

이때, 그래프를 표현하고 탐색하는 방법

- 인접 행렬 : sparse 그래프일 때
- 인접 리스트 : dense 그래프 일 때


인접 리스트 같은 경우에는
graph = [ [] for _ range(vertex 수)]
간선 정보 그대로, 뒤집고 로 리스트에 추가해주면 된다.
"""


from sys import stdin

n, m, v = map(int, stdin.readline().split())

# index 값과 일치 시키기 위해 padding
graph = [[0]*(n+1) for _ in range(n+1)]

# graph 채우기 -> 인접행렬
for _ in range(m):
    # undirected graph
    line = list(map(int, stdin.readline().split()))
    graph[line[0]][line[1]] = 1
    graph[line[1]][line[0]] = 1

# dfs, bfs
def dfs(start, visited):
    # 시작점 담아두고
    visited += [start]
    
    # 해당 줄을 전부 탐색한다. (row, 곧 degree의 값이 된다.)
    for c in range(len(graph[start])):
        if(graph[start][c] == 1 and (c not in visited)):
            dfs(c, visited)

    return visited


def bfs(start):
    visited = [start]
    queue = [start]

    while queue:
        n = queue.pop(0)
        for c in range(len(graph[start])):
            # pop 해놓은 애를 기준으로 bfs
            if(graph[n][c] == 1 and c not in visited):
                visited.append(c)
                queue.append(c)

    return visited

print(*dfs(v,[]))
print(*bfs(v))    
        