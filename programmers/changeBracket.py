"""
- 균형잡힌 괄호 = 개수 같음 / 올바른 괄호 = 개수, 짝맞음
- 더 이상 분리할 수 없다 = 괄호의 개수가 같다.

# 주어진 알고리즘대로 만들면 되는데, 뭔가 이 재귀적으로 반복되는 걸 못 짜겠는다.
0. 균형잡힌 문자열로 분리하기 (O)
1. 올바른 괄호 문자열인지 판별하기 (O)

--- 여기서부터 안됨, 재귀적인 부분이 ---
2. 올바르게 만들기
3. 반복

** 오마이갓!!! 솔루션 함수 자체를 재귀시키면 되는거였음 ㅠ
"""
# 균형잡힌 괄호 문자열 2개로 나누기 (index 반환)
def divide(p):
    idx, left, right = 0,0,0
    
    for index,temp in enumerate(p):
        if(temp == "("):
            left += 1
        else:
            right += 1
            
        if(left == right):
            idx = index
            break
            
    return p[:idx+1], p[idx+1:]

# 올바른 괄호 문자열인가 판별 -> 스택을 이용하자
def isRight(p):
        stack = []
        for temp in p:
            if(temp=="("):
                stack.append(temp)
            else:
                if(len(stack)==0):
                    return False
                stack.pop()
        return True

# 와 대박.. solution 자체를 재귀로 돌릴 수 있는거네..
# "위와 같은 과정을 반복하라"
def solution(p):
    answer = ''
    
    # 입력이 빈 문자열인 경우, 빈 문자열 반환
    if(len(p)==0):
        return answer

    u, v = divide(p)
    
    if(isRight(u)):
        # 3-1
        return u + solution(v)
    else:
        
        #4-1
        answer = "("
        
        #4-2
        answer += solution(v)
        
        #4-3
        answer += ")"
        
        # for 문에도 이렇게 쓸 수 있구나 대박.. 
        for temp in u[1:len(u)-1]:
            if(temp=="("):
                answer += ")"
            else:
                answer += "("
        
    
    return answer