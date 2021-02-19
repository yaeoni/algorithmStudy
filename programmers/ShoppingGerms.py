# 내 문제는 완전탐색으로 가는 조건을 잘 못 세우겠다는 것!!
def solution(gems):  
    answer = [0,0]
    
    # 중복을 허용하지 않는 set 을 이용해 count 셀 수 있음
    typeCount = len(set(gems))
    gemsSize = len(gems)
    
    start, end = 0,0
    
    temp = {}
    candidates =[]
    # 순차적으로 끝까지 가야하는 완전 탐색으로 풀어야함.
    while(True):
        # start가 끝까지 갔을 때 break
        if start == gemsSize:
            break
        
        if len(temp) == typeCount:
            # 보석이 적어도 1개 이상 포함 되어 있을 때, 답이 될 수 있으므로 추가
            candidates.append([start, end])
            
            # 계속 탐색을 해야하기 때문에 여기서 또 start 늘려주면 된다.
            temp[gems[start]] -= 1
            if temp[gems[start]] == 0:
                del temp[gems[start]]
            start += 1
            continue
            
        # 이놈 때문에 index out of range가 나는데, 왜 나는지 모루ㅡ겟따.
        # 아 원래는 end가 gemsSize-1까지밖에 안가는데, start를 늘리면서 len(temp)가 typeCount와 달라지는 현상이 생겨서 그럼 아하.
        if end == gemsSize:
            break
            
        # end 를 늘려주면서 보석 종류를 늘린다.
        if len(temp) != typeCount:
            if gems[end] not in temp:
                temp[gems[end]] = 1
            else:
                temp[gems[end]] += 1
                
            end+=1
            continue
        
    
    minLength = 100001
    
    for s, e in candidates:
        if minLength > e-s:
            minLength = e-s
            answer[0] = s+1
            answer[1] = e
            
    return answer

# 틀린 풀이
def solution(gems):
    
    answer = []
    types = {}

    for item in gems:
        if item not in types:
            types[item] = 1
        else:
            types[item] += 1
    
    typeCount = len(types)
    
    start = 0
    end = 0
    
    """
    내 생각으로 구현하자면
    빈 dict를 만들고 len(dict)가 typeCount가 될 때까지 end를 늘려서 계속 추가해준다.
    typeCount가 되었으면 그때부터 start를 하나씩 늘려가면서 dict 요소를 빼줌
    len 계속 확인하면서 typeCount 보다 딱 낮아질 때 !! 가 답
     => 틀림 와이? 가장 짧은 구간을 잡아야하는데 그게 안된다.
     => 그러면 끝까지 가야하거든 그러면 하나의 while문에서 해결을 해야돼 
      => 즉 !! 끝까지 탐색을 해야하는 완전 탐색 문제인데.. 저번에도 했는데 ㅜㅜ
    """
    
    temp ={}
    
    while(len(temp) < typeCount):
        if gems[end] not in temp:
            temp[gems[end]] = 1
        else:
            temp[gems[end]] += 1
        end += 1
    
    while(len(temp)==typeCount):
        temp[gems[start]] -= 1
        
        if(temp[gems[start]]==0):
            del temp[gems[start]]
        
        start += 1
    
    answer.append(start)
    answer.append(end)
    return answer