"""
0. 공백 기준 구분이니까 split 함수로 잘라주기
1. 정수 범위를 몰라서 min, max를 어느정도까지 선언해놔야할지 모르겠음. -> 걍 알아서했음!
    (min, max는 각 각 가장 큰 값, 가장 작은 값으로 default를 설정해놔야된다)
------------- edge 케이스 --------------
- 똑같은 숫자가 나올 경우
"""
def solution(s):
    answer = ''
    token = s.split(" ")
    
    min = 999999999
    max = -999999999
    
    for item in token:
        if(min > int(item)):
            min = int(item)
        
        if(max < int(item)):
            
            max = int(item)

    return str(min)+" "+str(max)