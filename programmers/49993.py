"""
순서가 정해져있기 때문에 선행스킬의 idx를 이용한 연산 진행
"""
def solution(skill, skill_trees):
    answer = 0
    
    for tree in skill_trees:
        
        flag = True;
        pos = 0
        
        for cur in tree: 
            temp = skill.find(cur)
            if temp != -1: # 없으면 -1 반환
                if pos == temp: pos += 1
                else:
                    flag = False
                    break
            else: continue
            
        
        if flag: answer += 1
    return answer