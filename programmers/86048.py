"""
1. 회의실 아무도 없다 -> 입실
2. 퇴실 할 수 있는 사람이 생길 때까지 -> 입실
3. 퇴실처리
4. 3에서 퇴실한 사람은 회의실에 남아있던 사람들과 반드시 만남.

WOW
"""
from collections import deque

def solution(enter, leave):
    answer = [0] * len(enter)
    
    enter, leave = deque(enter), deque(leave)
    conf = []
    
    while leave:
        if not conf:
            conf.append(enter.popleft())
            
        while enter and leave[0] not in conf:
            conf.append(enter.popleft())
            
            
        # 퇴실
        out = leave.popleft()
        conf.remove(out)
        
        for p in conf:
            answer[p-1] += 1
            answer[out-1] += 1
    return answer