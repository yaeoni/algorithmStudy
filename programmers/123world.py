"""
- 어떤식으로 변환되는가? -> 점점 늘어나는 조합처럼!
- 끝이 1,2,4 주기로 계속 바뀌면서,, 진법 처리?
11 : 42
12 : 44
13 : 111
14 : 112
15 : 114
16 : 121
17 : 122
18 : 124
19 : 141
20 : 142 ... 이런식으로 변환이 되는데, 이런 구조를 코드로 어떻게 써야할까? 감이 잘 안잡힌다ㅠ 

- 수학적 규칙이 따로 있지 않을까? 하는 생각 이어보기!
- 나머지가 0 일 때 몫에서 1빼는 생각을 하지 못했음!
"""
from collections import deque

def solution(n):

    queue = deque()
    
    while(1):
        
        remain = n%3
        n = int(n/3)
        
        if(remain ==0 ):
            n -= 1
        
        
        if(remain==0):
            queue.appendleft('4')
        elif(remain==1):
            queue.appendleft('1')
        else:
            queue.appendleft('2')
        
        if(n==0):
            break
    
    return ''.join(queue)