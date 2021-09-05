# +1 해서 나눠도 몫은 다음 라운드로 같아짐
def solution(n,a,b):
    answer = 0
    
    while(a!=b):
        answer += 1
        a = (a+1)//2
        b = (b+1)//2 
    return answer