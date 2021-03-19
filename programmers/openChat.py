"""
- 구분하기 Enter(1), Leave(2), Change(3) 
- 유저 아이디 / 닉네임  -> Enter와 Leave의 순서 존재.
- 아이디 순서대로 배열에 집어넣고(아이디, enter or Leave), 
- 닉네임은 dictionary로 ID-nickname 선언
- 마지막에 trace를 돌면서 id에 해당하는 닉네임과 같이 넣어주기
"""

def solution(records):
    answer = []
    
    trace =[]
    nickname = {}
    
     
    for record in records:
        # [0]=함수 , [1]=id, [2]=nickname
        token = record.split(" ")
        
        if(token[0]=="Enter"):
            nickname[token[1]]=token[2]
            trace.append(((token[1]), 1))
        elif(token[0]=="Change"):
            nickname[token[1]]=token[2]
        else:
            trace.append(((token[1]), 2))
    
    for id, func in trace:
        if(func==1):
            answer.append(nickname[id]+"님이 들어왔습니다.")
        else:
            answer.append(nickname[id]+"님이 나갔습니다.")
    return answer