# yaewon version
import heapq
from collections import deque

def solution(priorities, location):
    answer = 0
    
    heap = []
    queue = deque()
    for i, num in enumerate(priorities):
        heapq.heappush(heap, (-num, num))
        queue.append(i)
    
    idx = queue.popleft()
    p = heapq.heappop(heap)[1]
    
    while(1):
        if(p == priorities[idx]):
            answer +=1
            if(idx == location):
                break
            else:
                idx = queue.popleft()
                p = heapq.heappop(heap)[1]    
        else:
            queue.append(idx)
            idx = queue.popleft()
        
    return answer


# answer version - only using heapq
from collections import deque

def solution(priorities, location):
    answer = 0
    
    queue = deque([(v,i) for i,v in enumerate(priorities)])
    
    while(1):
        item = queue.popleft()
        
        # popleft로 인해서 queue가 비면 max가 안돌아가니까, if문에 queue 존재 여부도 확인 해야한다.
        if (queue and max(queue)[0] > item[0]):
            queue.append(item)
        else:
            answer += 1
            if(item[1] == location):
                break
            
        
    return answer