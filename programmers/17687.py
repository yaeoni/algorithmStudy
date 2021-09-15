def change(n, b):
    ret = ""
    if(n == 0):return "0"

    while(n > 0):
        r = n % b
        
        if(r < 10): ret += chr(r + ord('0'))
        else: ret += chr(r -  10 + ord('A'))
        
        n //= b
    
    ret = ret[::-1]
    return ret

def solution(n, t, m, p):
    answer = ''
    
    p -= 1
    turn = 0
    count = 0
    number = 0
    
    flag = True
    
    while(flag):
        
        s = change(number, n)
        
        for c in s:
            if count == t:
                flag = False
                break
            
            if(p == turn % m):
                count += 1
                answer += c
            
            turn += 1
        number += 1
    return answer