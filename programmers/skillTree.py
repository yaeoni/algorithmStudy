# 내가 푼 버전
def solution(skill, skill_trees):
    answer = 0

    for item in skill_trees:
        i = 0 
        flag = True
        for char in item:
            if(char in skill):
                if(char == skill[i]):
                    i += 1
                    continue 
                else:
                    flag = False
                    break
        
        if(flag == True): answer += 1
    return answer

# 좀 더 간단한 풀이
def solution(skill, skill_trees):
    answer = 0
    
    for item in skill_trees:
        # 매번 List 형식으로, 새로운 변수로 만들어줘야 아래 팝 을 자유로이 할 수 있음
        skill_list = list(skill)
        
        for char in item:
            if char in skill:
                if char != skill_list.pop(0):
                    break
        else:
            answer +=1
            
        
    return answer