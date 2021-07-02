# 방향, 가중치 그래프 나타내기
# 방향은 그래프 만들 때 반대로 안넣으면 된다.
# 가중치는 값 자체를 1말고, 가중치 값으로 넣기
# 여기서 최단경로?!
from sys import stdin

v, e = map(int, stdin.readline().split())
k = map(int, stdin.readline())
graph = [ [0]*(v+1) for _ in range(v+1)]

for _ in range(e):
    edge = list(map(int, stdin.readline().split()))
    graph[edge[0]][edge[1]] = edge[2]




print(graph)

