"""
- 파이썬 -> import heapq 이용해 우선순위 큐 구현하기
"""

import heapq

def solution(scoville, K):
    answer = 0
    
    heap = []
    
    # heap에 삽입
    for v in scoville:
        heapq.heappush(heap, v)
        
    while heap[0] < K and len(heap) > 1 : 
        answer += 1
        
        first = heapq.heappop(heap)
        second = heapq.heappop(heap)
        
        heapq.heappush(heap, first + second*2)
        
    if len(heap) == 1 and heap[0] < K:
        return -1;
    return answer