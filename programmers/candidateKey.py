"""
# 구성하는 컬럼의 개수로 판단하면 안된다는거... 첨 알았네 후보키의 이런 특징을 ㅎ
-> 근데 코딩을 도통 어떻게 하는가 ?!

생각0) 모든 조합을 다 시도하다가 (작은 경우 부터)
    후보키가 결정되면, 해당 튜플값은 더이상 안봐도 된다. 포함 안해도된다.
    
    검사 ) 각 string들 join해서 붙여서 똑같지 않으면 구분가능한거지
    
* 파이썬에서 조합 돌리기 .. 이제제발기억해
    from itertools import combinations
    list(combinations(조합할놈, 개수))

* remove vs discard
    remove는 지우려는 원소가 없으면 error
    discard는 지우려는 원소가 없어도 그냥 지나간다.

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

# 다른 사람 풀이 -> 좀더 깔끔한..

def solution2(relation):
    row = len(relation)
    col = len(relation[0])

    # 후보키가 될 수 있는 key 조합 계산
    candidates = []
    for i in range(1, co1+1):
        # 요렇게 조합 때릴 수도 있구나..신기
        candidates.extend(combinations(range(col, i)))

    # 유일성 추리기
    unique = []
    for candi in candidates:
        # 각 인덱스 해당 속성 튜플로 뽑기 / set처리후 (중복 거르기) 행 개수 동일한지 확인 / unique담기
        tmp = [ tuple([item[i] for i in candi] for item in relation)]
        if len(set(tmp))== row:
            unique.append(candi)

    # 최소성 추리기
    answer = set(unique)

    for i in range(len(unique)):
        for j in range(i+1, len(unique)):
            # 현재요소 - 다음요소와의 교집합 구하기 = 교집합해서 길이 같으면 부분집합이니까 최소성 만족X , 그리고 순서대로 넣어지니까 다음거만 봐도 괜찮은 거다.. 왕!
            if(len(unique[i]) == len(set(unique[i]) & set(unique[j]))):
                answer.discard(unique[j])

    return len(answer)