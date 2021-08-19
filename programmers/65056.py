# key = len 이라는 멋진 기준을 넣을 수 있었다 역시 파이썬인가,,

def solution(s):
    answer = []
    s = s[2:-2].split("},{")
    s=sorted(s, key=len)
    
    # dic를 이용해 중복검사
    dic = {}
    for v in s:
        temp = list(map(int, v.split(',')))
        
        for num in temp:
            if num in dic: continue
            else: 
                dic[num] = 1
                answer.append(num)
        
    return answer