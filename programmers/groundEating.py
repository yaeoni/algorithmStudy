"""
- 열의 개수가 4개로 고정 
- 같은 열을 연속해서 밟을 수 없다!

----------- 첫번째 생각 -----------
- 항상 제일 큰거 고르되, 같은 열만 아니게 하면 되지 않을까?
    => 같은 열에 있떤 놈이 내가 방금 고른거보다 크면 손해임

- 모든 시작점에서 계산을 해야지. 다음으로 나아갈 때에는 같은열이 아니되 & 가장 큰 값으로
    => bfs, dfs 이용하기? 노! 안했음

- 시작점에서부터 나아가는거 포문 어케짬? 
    음 열이 4개로 고정이니까 인덱스값을 열로 두는 1차원 배열값을 계쏙 업데이트하는건어때?
    0. candidate 배열 = 첫 값만 모아놓음 (ex. [1, 2, 3 5])
    1. land 첫 값 빼놓기
    
- 1차원 배열값을 업데이트하는법 = 자신의 열을 제외하고 가장 큰 놈 고르기 ~ 구현을 어떻게해볼까
    0. 하나의 행을 받아서, 해당하는 열 숫자를 지우고 거기서 max값 넣기
    

=> 테스트 케이스만 맞고 나머진 다틀림 ㅍㅎㅎ 아대박... 나는 계속 "계쏙 같은 열을 참조하지 못하게 했음"
   ~ 매번 그 열은 바뀌어야하는데.. 와웅. => "인덱스 값이 업데이트 되도록" 세팅해보자. 
  
*** 매번 고정된 맥스값으로 하면 안돼. 왜?! 중복되는 값이 있으면 뒤에 더 큰놈이 있을수도 있는거라서..
그냥 bfs, dfs 써야돼!!! ~ dp로 최대값 저장하는것도 좋아보이긴하는데.. 여러가지 생각이 든다.
~ 옛날에 해본 그 금광캐기 문제랑 비슷한것 같은데

----------------- 두번째 생각 ---------------
(level, index, value) 의 형식으로 max값인 놈을 다 넣어주기 
queue에 넣고, 계속 pop 하면서 index가 아닌 애뜰 제외한 멕스값을 더해 넣어주기...

하,,,,,, 다 틀림.. 멘탈 바사삭이네용... 반례도 하나 고쳤는데.. 세상에 이 접근법 이닌가봐 ㅠ쉬ㅏ발 안해

-> 무엇이 틀렸을꼬
~ 틀린 이유 ~
: 해당 열을 제외한 행의 max 값만을 담는 것이 답이 아님 ** 내가 고를 수 없는 값이 더 답 크게 만들 수 있잖아!!! 
=> 그래서 DP를 써야함! // 생각을 하긴 했는데, 괜히 어렵다고 느껴서 잘 못 다가간 것 같다.ㅠ

------------ 검색즈 ---------------
DP 사용 (land에 이전 행의 최댓값을 더해간다, but 같은 열은 제외하고)


land[i+1][0]= max(land[i][1], land[i][2], land[i][3]) + land[i][0]
: 이전 행의 최댓값을 구해서 넣는거니깐, 아래->위 방향으로 더한다는 느낌(나와는 다른 열을 가진 위에 놈을 더한다.)
"""

def solution(land):
    answer = 0
    
    for i in range(len(land)-1):
        land[i+1][0]= max(land[i][1], land[i][2], land[i][3]) + land[i+1][0]
        land[i+1][1]= max(land[i][0], land[i][2], land[i][3]) + land[i+1][1]
        land[i+1][2]= max(land[i][0], land[i][1], land[i][3]) + land[i+1][2]
        land[i+1][3]= max(land[i][0], land[i][1], land[i][2]) + land[i+1][3]
        
    return max(land[-1])


# 틀린 풀이 = 이전 열에 해당하는 값을 제외한 각 행에서 가장 큰 값으로 답 만들기 / 내 딴에는 경우들 다 체크했다고 생각했는데, 아닌가보다. ㅠ 
# 어떤 해결법 같은게 떠올랐을 때 너무너무 복잡하면 다른 방법이  있지 않을까 생각하는게 좋을듯!
from collections import deque
def solution(land):
    answer = 0
    
    candidate = []
    
    queue = deque()
    for idx, num in enumerate(land.pop(0)):
        queue.append((0, idx, num))
    
    #print(queue)
    size = len(land)
    
    while(queue):
        
        #print("push after 1 row : ",queue)
        
        item = queue.popleft() # (level, idx, sum)
        

        if(item[0]== size):
            candidate.append(item[2])
            continue
            
        row = land[item[0]]
        
        # 같은 열은 밟을 수 없고, 나머지 중에 최대를 골라야댐
        deleted = row[item[1]]
        row[item[1]] =0
        
        #print("row",row)
        maxVal = max(row)
        #print("max:", maxVal)
        for idx, num in enumerate(row):
            if(num == maxVal and idx != item[1]):
                queue.append((item[0]+1, idx, item[2]+maxVal))
                
        row[item[1]] = deleted        
    #print(candidate)
    return max(candidate)