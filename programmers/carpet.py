"""
가로 a, 세로 b라 할 때
yellow = a*b
brown = 2a + 2b + 4

만족하는 수를 while문으로 돌려서 확인하면 된다.
"""

def solution(brown, yellow):
    answer = []
    
    for a in range(1, yellow+1):
        if(yellow % a == 0):
            b = int(yellow/a)
            if(2*a +2*b +4 == brown):
                # 작은 수부터 확인하기 때문에! 작은 놈을 세로로 리턴 시키면 된다.
                answer =  [b+2, a+2]
                break
    return answer
    