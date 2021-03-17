"""
- 인접한 풍선 중 하나 터뜨리기 / 작은 거 터뜨리는건 단 한 번만
- 최후까지 남기는 것이 가능한 풍선들의 개수

예시) 각 풍선들을 최후까지 남기는 법 고안하기

아니면 어차피 개수를 구하는 거니깐 모든 경우의 수 다 돌고 len(a)==1인 경우를 세면 되지 않나.

------------- 첫번째 생각 --------------
- chance라는 변수 두기 = 작은 것 터뜨리기 찬스
- 터뜨리기 ~ 모든 경우 생각하면서 하기?
    1. 인접쌍을 구한다. 
    2-1 chance를 쓴다 / chance를 안쓴다.
    2-1 쓰면 작은 놈 / 안 쓰면 큰놈 del시키는데, 이때 Protect일 시 return False처리하기
    3. 하나라도 가능한 경우가 있으면 answer += 1
    
=> 매번 모든 인접쌍을 구해야한다는 점에서 fail, 넘 overhead가 클 듯 !
----------- 홍's 가이드 ------------
- 최후에 남는 경우를 남긴다 = 지워질 수 밖에 없는 놈을 지우고 남은 것들
- 양 옆에 자기보다 작은 놈이 있는 경우 지워질 수 밖에 없음 = 찬스를 2번 쓸 수 없으니까.

=> 스택을 활용해서 구하면 된다! 
=> 양 옆에 자기보다 작은 놈이 올 때, pop한 뒤에도 체크를 해줘야한다.
~ 이 pop하는거 뒤에도 체크를 해주는거 짜는게 좀 고통 중 .. if, break문을 잘쓰자.
"""
def cleaning(stack):
    top = len(stack)-1
    
    while(True):
        if(len(stack) < 3):
            break
        
        comp2 = stack.pop()
        center = stack.pop()
        comp1 = stack.pop()
        
        stack.append(comp1)
            
        if(center < comp1 or center < comp2):
            stack.append(center)
            stack.append(comp2)
            break
        else:
            stack.append(comp2)

def solution(a):
    stack = []
    for item in a:
        stack.append(item)
        
        if(len(stack) < 3):
            continue
        else:
            cleaning(stack)
        
    return len(stack)