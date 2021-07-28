"""
c++ 의 풀이법과 마찬가지로 풀으려면
큐에서 index값을 함께 저장해야하는데, 파이썬이 불가능할리 없었다 ㅎ

- 큐 속에서 자체 max값을 찾을 수 있다면 따로 (정렬 위한)우선순위큐를 구현할 필요 없이
- idx, value가 존재하는 큐 하나만으로 풀 수 있는 것이었다.!
    => 하지만 이때에는 해당 문서가 가장 큰 우선순위인지 판단하고
        pop시켜줄 때 해당 queue 속 data가 존재하는지 여부도 체크해야함
    => 어떻게 보면 큐를 두 개 만드는 것도 속 편한 방법인 것 같다.
    
"""
from collections import deque

def solution(priorities, location):
    answer = 0
    
    # python틱하게 deque를 정의하는 방법도 잘 기억해두자.
    queue = deque([(v, i) for i, v in enumerate(priorities)])
    
    cnt = 0
    while queue:
        data = queue.popleft()
        
        value = data[0]
        index = data[1]
        
        # 더 큰 우선순위가 존재하면 append -> popleft시 queue가 비어버릴 수 있기에 따로 처리
        if queue and (max(queue)[0] > value):
            queue.append(data)
        # 해당 문서의 우선순위가 가장 크다면
        else:
            answer += 1
            if(index == location):
                break
        
        cnt += 1
        
    return answer