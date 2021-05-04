# 재귀를 이용한 DFS
def solution(numbers, target):
    answer = 0
    n = len(numbers)
    
    def dfs(idx, result):
        if idx == n :
            if result == target:
                nonlocal answer
                answer += 1
            return
        else:
            dfs(idx+1, result+numbers[idx])
            dfs(idx+1, result-numbers[idx])
        
    #dfs 함수의 시작
    dfs(0, 0)
    return answer


# dequeue를 이용한 DFS
from collections import deque
def solution(numbers, target):
    answer = 0
    queue = deque()
    n = len(numbers)
    
    # 다음 index에 해당하는 원소를 더하거나, 빼야하므로 해당 인덱스를 함께 저장
    queue.append([numbers[0],0])
    queue.append([-1*numbers[0],0])
    
    while queue:
        temp, idx = queue.popleft()
        idx += 1
        
        if idx < n:
            queue.append([temp+numbers[idx], idx])
            queue.append([temp-numbers[idx], idx])
        
        # 모든 숫자가 더하거나 빼졌을 때
        else:
            if temp == target:
                answer += 1
                
    return answer

# DFS건, BFS건 상관 없음 -> 보내주는 index값으로 계산하기 때문에.