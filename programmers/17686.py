# python sort 함수는 stable을 보장한다!
# cmp_to_key를 이용한 compare 함수가 동작하지 않는 이유는,,ㅠ => T,F 가 아니라 0, -1, 1 을 반환해야하는건가보다!! 완전 맞는말
# -1 :  현상 유지(앞에것이 앞으로) 
from functools import cmp_to_key

def compare(x, y):
    nx = x[0].lower()
    ny = y[0].lower()
    
    if nx > ny:
        return 1
    elif nx < ny:
        return -1
    else:
        if int(x[1]) > int(y[1]):
            return 1
        elif int(x[1]) < int(y[1]):
            return -1
        else:
            return 0
        
    
def solution(files):
    answer = []

    v = []
    for file in files:
        header = ""
        number = ""
        tail = ""
        
        flag = 0
        
        for c in file:          
            if(c.isdigit()):
                #  아  , , ,,,, digit이기만 하면 1로 바꿔서 문제였다
                if(flag ==0): flag = 1
            elif(flag == 1): 
                flag = 2
                
            if len(number) == 5 : flag = 2
                
            if(flag == 0): header += c
            elif(flag == 1): number += c
            else: tail += c
                
        temp = [header, number, tail]
        v.append(temp)
    
    v = sorted(v, key=cmp_to_key(compare))
    
    for splits in v:
        s = ""
        for split in splits:
            s += split
        answer.append(s)
    return answer

# new version
# python sort 함수는 stable을 보장한다!
# sort key에 lambda 를 활용하자
def solution(files):
    answer = []
    
    for file in files:
        
        head, number, tail = "", "", ""
        flag = False
        
        for i in range(len(file)):
            # number에 추가
            if file[i].isdigit() and len(number) < 5:
                number += file[i]
                flag = True
            # 아직 number가 나오지 않았다면 header
            elif not flag:
                head += file[i]
            # 넘버가 나오고, 숫자도 아니면 나머지는 tail
            else:
                tail += file[i:]
                break
                
        # tuple로 저장
        answer.append((head, number, tail))
            
    # sort , header->number 순으로 와! 이러니까 cmp_to_key를 쓸 필요가 없구나
    answer.sort(key = lambda x : (x[0].upper(), int(x[1])))

    return [''.join(t) for t in answer]