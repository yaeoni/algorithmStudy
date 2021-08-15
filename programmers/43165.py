# dfs로 풀어보기
# target에 도달하면 끝
# 안 도달하고 더 넘기려면?! 어떻게 짜야하드라.,.,
# python은 call by reference 형식 노 노 . 배열같은건 전달되지만 값은 안된다.

answer = 0;
def dfs(idx, numbers, value, target):
    global answer;
    if(idx == len(numbers)):
        if(value==target):
            answer += 1
            return
    else:
        dfs(idx+1, numbers, value+numbers[idx], target)
        dfs(idx+1, numbers, value-numbers[idx], target)
    
def solution(numbers, target):
    
    dfs(0, numbers, 0, target)
    
    return answer