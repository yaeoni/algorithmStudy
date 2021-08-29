"""
- 우선순위 큐를 이용한 풀이
- dijkstra 적용
- adj는 (목적지, cost) 고 / pq는 (cost, 목적지) 라는 것! 헷갈 노노
"""

import heapq
import collections

def solution(N, road, K):
    answer = 0
    
    # 애초에 인접 리스트를 dict로 설정해도 아무 상관이 없음!
    adj = collections.defaultdict(list)
     
    for u, v, w in road:
        u -= 1
        v -= 1
        adj[u].append((v, w))
        adj[v].append((u, w))
        
    pq = [(0, 0)]
    
    dist = [500001] * N
    
    # 으익! 시작점 초기화를 안해줘서 틀린거였따! ㅎ;ㅋ;ㅋ;
    dist[0] = 0
    
    while pq:
        cost, now = heapq.heappop(pq)
        
        if cost > dist[now]: continue
        
        for next, curCost in adj[now]:
            nextCost = curCost + cost
            
            if(nextCost < dist[next]):
                dist[next] = nextCost
                heapq.heappush(pq, (nextCost, next))
                
        
    for v in dist:
        if v <= K: answer += 1
    return answer