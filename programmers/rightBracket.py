# 어제 풀었던 괄호변환의 새끼문제같은..! 그래서 그냥 풀었다. 너무 쉬웠어..
# 파이썬이라 스택 활용이 쉬웠던 걸 수도 있으니깐, 다른 언어 풀이 버전도 봐봐야겠따. 씨플플.. -> 똑같았다.

def solution(s):
    answer = True
    
    stack = []
    
    for temp in s:
        if(temp =="("):
            stack.append(temp)
        else:
            if(len(stack)==0):
                return False
            stack.pop()
            
    if(len(stack) !=0):
        return False
    return True