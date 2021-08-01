"""
- 해당 기능이 배포되는데 걸리는 날짜를 계산하는 방식 활용해보기 (큐 이용)
- 남은 날짜를 계산하는 과정에서 틀렸었다.
"""
from collections import deque
import math
def solution(progresses, speeds):
    answer = []
    
    # 기능 개발하는데 필요한 일 수 <- 여기서 틀렸었다.
    q = deque()
    for i in range(len(progresses)):
        day = (100 - progresses[i]) / speeds[i]
        if day % 1 != 0:
            day = math.floor(day) + 1
        q.append(int(day))
    
    day = q.popleft()
    count = 1
    while(q):
        temp = q.popleft()
        if(day < temp):
            answer.append(count)
            day = temp
            count = 1
        else:
            count += 1
    answer.append(count)
    return answer