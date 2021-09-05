# 파이썬에서는 list로 stack을 쓴다
def solution(s):
    answer = 0
    
    st = []
    
    for c in s:
        if(len(st) == 0 or st[-1] != c): st.append(c)
        else: st.pop()
            
    if(len(st)==0): answer = 1 

    return answer