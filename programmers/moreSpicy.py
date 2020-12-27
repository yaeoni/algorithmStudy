
# heapq 모듈을 사용하자!
import heapq

def solution(scoville, K):
    answer = 0
    heap = []
    for val in scoville:
        heapq.heappush(heap, val)
        
    while heap[0] < K:
        try:
            heapq.heappush(heap, heapq.heappop(heap) +(2*heapq.heappop(heap)))
        except IndexError:
            return -1
        answer+=1

    return answer

"""
# 테스트 케이스에선 통과했으나, 효율성에서 fail. 나름대로 heap을 짰다고 생각했는데..
def insert(scoville, data):
    scoville.append(data)
    
    child = len(scoville)-1
    parent = int(child/2)-1
        
    while(child > 0 and scoville[parent] > scoville[child]):

        scoville[parent], scoville[child] = scoville[child], scoville[parent]
        child = parent
        parent = int(child/2)-1

def pop(scoville):
    ret = scoville[0]
    temp = scoville.pop()
    
    if(len(scoville) == 0):
        return ret
    else:
        scoville[0] = temp
        
    parent = 0
    child = 1
    
    if(child+1 <= len(scoville)-1):
        if(scoville[child] > scoville[child+1]):
            child = child+1
        
    
    while(child <= len(scoville)-1 and scoville[parent] > scoville[child]):
        scoville[child], scoville[parent] = scoville[parent], scoville[child] 
        
        parent = child
        child = parent*2
        
        
        if(child+1 <= len(scoville)-1):
            if(scoville[child] > scoville[child+1]):
                child = child+1
    
    return ret

def solution(scoville, K):
    answer = 0
    
    scoville.sort()
    
    while(scoville[0] < K):
        
        if(len(scoville) == 1):
            return -1
        
        first = pop(scoville)
        second = pop(scoville)

        newScoville = first + 2*second

        insert(scoville, newScoville)

        answer +=1
   

    return answer
"""