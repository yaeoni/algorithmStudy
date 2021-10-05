import heapq # 파이썬에서는 min heap으로 기본 동작
# pq 정렬기준은 실행시간 기준
# 정렬 기준 때문에 실행시간[1] 을 앞으로 넣어야한다.
def solution(jobs):
    answer = 0
    
    jobs = sorted(jobs)
    pq = []
    
    idx, time = 0, 0
    
    while idx < len(jobs) or pq:
        # 실행시간 내고, 넣을 수 있다면
        if idx < len(jobs) and time >= jobs[idx][0]:
            j = jobs[idx]
            heapq.heappush(pq, [j[1], j[0]])
            idx += 1
            continue # 이런 경우가 더 있을 수 있으니 continue!!
        # 우선순위 큐 처리
        if pq:
            # 작업 시간 추가
            p = heapq.heappop(pq)
            time += p[0]
            
            # 기다린 시간까지 추가
            answer += time - p[1]
            
        # 큐가 비었다면 시간 옮기기     
        else:
            time = jobs[idx][0]

    return answer // len(jobs)