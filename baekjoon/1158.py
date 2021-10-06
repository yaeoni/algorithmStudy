# deque를 이용해서!
from collections import deque
import sys

n, k = map(int, sys.stdin.readline().split())

q = deque()

for i in range(1, n+1):
    q.append(i)

answer = []
while q:
    for j in range(0, k-1):
        first = q.popleft()
        q.append(first)
    
    answer.append(q.popleft())


answer = ", ".join(map(str,answer))

print(f'<{answer}>')