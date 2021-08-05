def solution(p):
    answer = True
    
    p = sorted(p)
    
    for idx, value in enumerate(p):
        if(idx != len(p)-1):
            if value == p[idx+1]:
                continue
            
            if value == p[idx+1][:len(value)]:
                return False
    return answer