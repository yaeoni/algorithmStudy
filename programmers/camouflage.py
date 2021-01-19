# 경우의 수 = 각 개수를 각각 곱함
# 카테고리별로 개수 세기 + 1 (고르지 않는 경우 포함)
# 각 개수 곱하기 - 1 (모두 다 고르지 않았을 경우를 위해 -1)
def solution(clothes):
    choice = {}
    
    for data in clothes:
        choice[data[1]] = choice.get(data[1], 1) + 1
    
    result = 1
    
    for temp in choice.values():
        result *= temp
        
    result -= 1
    return result

# 다른 방식
# 컨테이너 값 활용할 수 있는 모듈 활용 ( Counter : 동일한 값 자료 몇개 ? ,  reduce : 여러개 data 대상으로 집계 )
def solution(clothes):
    from collections import Counter
    from functools import reduce
    cnt = Counter([kind for name, kind in clothes])
    answer = reduce(lambda x, y: x*(y+1), cnt.values(), 1) - 1
    return answer

# 다시 풀어보기 (my own)
def solution(clothes):
    result = 1
    
    choice = {}
    
    for item in clothes:
        # 의상종류가 없으면 만들어주고, 있으면 += 1
        if(item[1] in choice):
            choice[item[1]] +=1
        else:
            # 아예 뽑지 않는 경우가 필요하므로 2로 초기화 해야함
            choice[item[1]] = 2
        
            
    for item in choice:
        result *= choice[item]
    
    result -= 1
    return result