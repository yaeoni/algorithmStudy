# dictionary 이용해서!
# 파이썬 -> [:] 이용할 때, 마지막은 포함을 안함! 따라서 모든 글자를 다 표현하려면 길이와 같아져야함
def solution(msg):
    answer = []
    
    dic = {}
    
    # 사전 초기화
    for i in range(26):
        dic[chr(ord('A')+i)] = i+1
    
    next = 27

    # msg 자체를 줄이면서 풀이
    while msg:
        idx = 1
        
        # 사전에 해당 문자가 들어있지 않을 때까지 ! 반복
        while msg[:idx] in dic and idx <= len(msg):
            idx += 1

        # 문자 하나 빼주기 = 사전에 존재하는 글자로 
        idx -= 1
        
        if msg[:idx] in dic:
            answer.append(dic[msg[:idx]])
            
            # 사전 추가
            dic[msg[:idx+1]] = next
            next += 1
        
        msg = msg[idx:]

    return answer