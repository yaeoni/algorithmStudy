def isRight(p):
    r = 0
    
    for c in p:
        if c =='(': r +=1
        else: r -= 1
        
        if r < 0: return False
        
    return True
    
def solution(p):
    answer = ''
    
    # 1
    if(len(p) == 0): return ""
    # 2
    if(isRight(p)): return p
    splitIdx = 0
    r = 0
    for idx, c in enumerate(p):
        
        if c == '(': r += 1
        else: r -= 1
            
        if(r == 0):
            splitIdx = idx
            break
            
    u = p[:splitIdx+1]
    v = p[splitIdx+1:]
    
    # 3-1
    if(isRight(u)): return u + solution(v)
    
    # u 뒤집기 -> replace (,) 가 이미 바뀐 부분이 또 바뀔 수 있으니까 다른 문자로 바꿔놓고 바꾸기
    u = u.replace('(', '0').replace(')','(').replace('0', ')')

    return "(" + solution(v) + ")" + u[1:len(u)-1]