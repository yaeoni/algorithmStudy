"""
# 구성하는 컬럼의 개수로 판단하면 안된다는거... 첨 알았네 후보키의 이런 특징을 ㅎ
-> 근데 코딩을 도통 어떻게 하는가 ?!

생각0) 모든 조합을 다 시도하다가 (작은 경우 부터)
    후보키가 결정되면, 해당 튜플값은 더이상 안봐도 된다. 포함 안해도된다.
    
    검사 ) 각 string들 join해서 붙여서 똑같지 않으면 구분가능한거지
    
* 파이썬에서 조합 돌리기 .. 이제제발기억해
    from itertools import combinations
    list(combinations(조합할놈, 개수))

------------- 포기의 과정 ,, 안포기됐다!! --------------
0. 모든 col의 조합을 구한다.
1. 해당 col이 candidate가 될 수 있는지 판별한다. -> 같은 값이 있는지 확인한다.
2. 최소성 만족 조건을 넣어야한다. -> 여기서 막혔다. 부분집합이면 못들어가게 해야되는데..
    ( 튜플의 서브튜플 조건을 만들다.. A가 B의 부분집합인가? set(B).issubset(A) )
        ~ 부분집합이기만 하면 key가 될 수 없다.
"""
from itertools import combinations

def isKey(relation, candidate):
    compareStr = []
    
    flag = True
    for item in relation:
        temp = ""
        
        for idx in candidate:
            temp += item[idx]
        
        if(temp in compareStr):
            flag = False
        else:
            compareStr.append(temp)

    return flag
    
def solution(relation):
    answer = []
    
    # column 개수
    col = len(relation[0])
    index = []
    candidate =[]
    
    for i in range(col):
        index.append(i)
        
    for i in range(col):
        candidate.append(list(combinations(index, i+1)))
    
    for row in candidate:
        for item in row:
            if(isKey(relation, item)):
                
                # 부분집합인지 확인한다.
                flag = False
                for temp in answer:        
                    flag = set(temp).issubset(item)
                    if(flag==True):
                        break
                if flag == False:
                    answer.append(item)
    
    return len(answer)