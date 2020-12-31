# 내 버전
from functools import cmp_to_key

def compare(x, y):
    x = str(x)
    y = str(y)
    
    length = len(x)
    
    if(length > len(y)):
        length = len(y)
        
    # return -1 : x를 앞으로 보냄
    # return 1 : y를 앞으로 보냄
    # return 0 : 그대로 둔다
        
    for idx in range(length):
        if(x[idx] > y[idx]):
            return -1
        elif(x[idx] < y[idx]):
            return 1
        
    # 끝까지 다 갔는데 남은 경우 / 아예 똑같은 경우
    attach1= int(x+y)
    attach2 = int(y+x)
    if attach1 < attach2:
        return 1
    elif attach1 > attach2:
        return -1
    return 0
    
    
def solution(numbers):
    ret = sorted(numbers, key=cmp_to_key(compare))

    #[0,0,0,0]은 0000이 아니라 0을 리턴해야한다.
    if(ret[0] == 0): return "0"
    
    answer = "".join(map(str, ret))
    return answer

# 좀 더 깔끔한 버전, 애초에 처음부터 둘이 붙여가며 비교했으면 됐다.
import functools

def comparator(a,b):
    t1 = a+b
    t2 = b+a
    return (int(t1) > int(t2)) - (int(t1) < int(t2)) #  t1이 크다면 1  // t2가 크다면 -1  //  같으면 0

def solution(numbers):
    n = [str(x) for x in numbers]
    n = sorted(n, key=functools.cmp_to_key(comparator),reverse=True)
    answer = str(int(''.join(n)))
    return answer