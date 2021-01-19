import heapq
    
def solution(jobs):
    
    jobs.sort(reverse = True)
    
    # 현재 시각 기록용
    cur = 0 
    # 각 소요시간 합, 사이즈
    time = 0
    size = len(jobs)
    
    # 대기 목록 담을 우선순위 큐
    pq = []

    while(1):
        if(len(jobs)==0 and len(pq)==0): break
        
        # 힙큐에 계속 넣어줘야한다는 조건을 어떻게 세워야할 지 감이 안잡혔었다. ㅜㅜ
        if(jobs):
            item = jobs.pop()  
            if(cur > item[0]):
                heapq.heappush(pq, (item[1], item[0]))
                continue
            else:
                jobs.append(item)
                
        # 큐에 들어있으면 다 뺴주기
        if(pq):
            heapItem = heapq.heappop(pq)
            time += cur - heapItem[1] + heapItem[0]
            cur += heapItem[0]

        # 큐가 비어있으면 job에서 실행
        else:
            item = jobs.pop()
            
            # 시작시각이 현재시간보다 뒤라면, 먼저 온걸 처리하니깐 현재를 시작 시간으로 setting 해야한다..!!
            if(item[0] > cur):
                cur = item[0]

            time += cur - item[0] + item[1]  
            cur += item[1]
            
            
    return int(time/size)



