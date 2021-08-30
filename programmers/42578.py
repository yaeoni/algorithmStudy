# 미춌다리.
def solution(clothes):
    answer = 1
    
    dic = dict()

    for name, kind in clothes:
        if kind not in dic:
            dic[kind] = 1
        else:
            dic[kind] += 1

    for key in dic:
        answer *= (dic[key] + 1)
        
    return answer-1
    