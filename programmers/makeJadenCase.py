"""
0. 공백 기준이니까, split으로 자르고, 첫문자만 대문자로 바꾸고 나머진 소문자화
0-2. for 문으로 요소 하나씩 돌면서 확인해주기 / 분명 함수 있을텐데 없으면 이렇게 해야겠지.
1. 공백을 추가해주기 위해서 맨끝이 아니면 " " 추가해주기

# 파이썬은 아스키코드값 어떻게 알아내는거야.?ㅋ -> 대소문자간 32 차이남
    : ord -> 문자에 맞는 아스키 코드 반환 
    : chr -> 아스키코드에 해당하는 문자 반환
 
# 파이썬 대소문자 변환 함수 : upper(), lower() .. 쉽네 ㅎ => 안에 내용만 고쳐주면 된다.
* for문 안에서 중간 값을 바꿔도 반영이 안되더라!

"""
def solution(s):
    answer = ''
    #print(ord('A'), chr(91),chr(90+32), ord('a'))
    
    tokens = s.split(" ")

    for index, token in enumerate(tokens):
        for idx, i in enumerate(token):
            #print(idx, i)
            if(idx == 0) :
                # 첫글자가 소문자 -> 대문자로 바꿔주기
                if(ord(i) >= 97 and ord(i) <= 122):
                    i = chr(ord(i)-32)
                    token = token[:idx]+i+token[idx+1:]        
            else:
                # 중간에 대문자 있는 경우 -> 소문자로 바꿔주기
                if(ord(i) >= 65 and ord(i) <= 90):
                    i = chr(ord(i)+32)
                    token = token[:idx]+i+token[idx+1:]
                    
        answer += token
        if index != len(tokens)-1:
            answer += " "
    #print("token", tokens)           
    return answer