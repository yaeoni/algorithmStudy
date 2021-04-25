

"""
- split 처리 해서 2개씩 묶을까 했지만 -e 나오면 말짱 도로묵임

- 우선 flag_rule에 무엇이 포함 되어있는지 자르기

** 중요한 것은 기능의 추상화 **
* 각각의 정규표현식
* split 기준을 " -" 로 하면 !! 옵션 기준으로 나뉘잖아 와아하우
* 정규 표현식 이용해서.. 뚜따뚜따리
"""

# flag_rules 안의 flag_name과 flag_argument_type을 매핑시킨다.
def getRules(flag_rules):
    rules = {}
    for rule in flag_rules:
        tokens = rule.split(" ")

        if tokens[0] not in rules:
            rules[tokens[0]] = tokens[1]

    return rules

def isRight(tokens, rule):
    

def solution(program, flag_rules, commands):
    answer = []
    flag_rules = getRules(flag_rules)

    for command in commands:
        tokens = command.split(" ")

        if(tokens[0] != program):
            answer.append(False)
        else:
            # program 명 삭제
            tokens = tokens[1:]

            # 1. flag_name 이 먼저 오는가?(형식 검사)
            for token in tokens:
                if(token[0] != "-"):
                    answer.append(False)
                    break
                else:
                    # flag_rule에 존재하는 flag_name인가?(유효성 검사)
                    if token not in flag_rules:
                        answer.append(False)
                        break
                    else:
                        if(flag_rules[token]=="NUMBER" or flag_rules[token]=="STRING"):
                            # argument 있는 놈, 개수도 판단을 해줘야하잖어 ?+?
                            if(isRigth(tok))
                        else:
                            # argument 없는 null 놈
                            tokens = tokens[1:]
                answer.append(True)            
                        
    print("answer", answer)
    return answer


solution("line", ["-s STRING", "-n NUMBER", "-e NULL"], ["line -n 100 -s hi -e", "lien -s Bye"]) # [T, F]
#solution("line", ["-s STRING", "-n NUMBER", "-e NULL"], ["line -s 123 -n HI", "line fun"]) # [T, F]
