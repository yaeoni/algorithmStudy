"""
- J(A,B) = 교집합 / 합집합
+ 모두 공집합일 때는 1로 정의
+ 원소 동일한 거 여러개일 때는 (1개, 2개)라면 합집합에선 2개라고 침

- 두 글자씩 끊어서 다중집합의 원소로 만들기
- 영문자로된 글자쌍만 유효 / 대소문자 구분 없음

# 파이썬에서 알파벳인지 아닌지 확인하는 방법
----------------- 첫번째 생각 -------------------
0. 두글자 씩 끊기 - 토큰에 넣기 / 영문자 글자만 넣기 (O)
1. 교집합 합집합 구하기 -> 이거는 어디에 있을 삘인디.. => 없으면 만들면 된다! dict로 선언을 할까봐
2. 다중원소에 관한 처리
3. 띄어쓰기에 관한 처리

~ 마지막 테케에서 에러가 나는데 이유를 잘 모르겠는디?! : 이건 공집합 1로 안해놔서 그런거고..

@@@ 에러 7, 9, 10, 11 @@@
=> 합집합 세워줄 때 문제가 있는 것 같은데 증말.. 모냐!! 이건 이제 합집교집 구하는 법을 좀 알아보자

=> 교집합과 합집합을 같이 구하려 해서 그럼, token1엔 있는데 token2에 없는게 추가가 안되었음!!
=> 그래도 안되는건, counting이 아니라 appending하는 식으로 접근해서 안되는 것 같은데..

나의 방식은 list에 원소를 추가해주는거, 답 방식은 개수를 추가하는 방식. 똑같은듯 했지만 안되는 걸 봐서는.. 더 간단한 쪽으로 만들자 앞으로도!
"""

def slicing(input):
    ret = {}
    # 각각 두글자 씩 끊겠습니다. string에서 2씩 뛰면서 자르는 방법이 뭘까욘
    for i in range(0, len(input)):
        token = input[i:i+2]
        flag = True
        for idx, j in enumerate(token):
            if(len(token)!=2):
                # 공백이 존재하면 글자쌍 버리기
                flag = False
                break 
            elif(ord("a") <= ord(str(j)) and ord(j) <= ord("z") or ord("A") <= ord(j) and ord(j) <= ord("Z") ):
                # 대소문자 구분 X => 소문자로 바꿔주기
                token = token[:idx] + j.lower() + token[idx+1:]
            else:
                flag = False
                break
        
        if(flag):
            if token not in ret:
                ret[token] = 1
            else: 
                ret[token] +=1
        
    
    return ret

def solution(str1, str2):
    answer = 0
    
    token1 = slicing(str1)
    token2 = slicing(str2)

    andSet = 0
    orSet = 0
    
    # 교집합 구하기
    for item in token1:
        if item in token2:
            andSet += min(token1[item], token2[item])
            
    # 합집합 구하기
    for item in token1:
        if item in token2:
            orSet += max(token1[item], token2[item])
    
    for item in token1:
        if item not in token2:
            orSet += token1[item]
            
    for item in token2:
        if item not in token1:
            orSet += token2[item]
      
    if orSet == 0:
        return 65536
    elif andSet == 0:
        return 0
    
    return int(andSet/orSet * 65536)

