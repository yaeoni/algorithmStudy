def makeTokens(value):
    value = value.lower();
    print("START")
    ret = []
    for i in range(1, len(value)):
        temp = value[i-1:i+1]
        if(temp.isalpha()): 
            print(temp)
            ret.append(temp)
    return ret

def solution(str1, str2):
    
    answer = 0
    
    # 두 글자씩 끊기
    one = makeTokens(str1)
    two = makeTokens(str2)
    
    # 모두 공 집합일 경우
    if len(one) == 0 and len(two) == 0 : return 65536
    
    # 합집합, 교집합 개수 구하기
    uni = len(one) + len(two)
    inter = 0
    
    for val in one:
        if val in two:
            inter += 1
            two.remove(val) # two에 있는걸 빼줘야 한 번 체크한걸 또 체크 안함
    
    uni -= inter
    
    if uni == 0 : return 65536

    answer = inter / uni

    return int(answer * 65536) # 마지막에 int 처리를 해줘야함