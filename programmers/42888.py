"""
c++와 같은 방식으로 풀어내기
"""
def solution(record):
    answer = []
    
    user = {}
    order = []
    
    for value in record:
        tokens = value.split(" ")

        if tokens[0] == "Enter":
            user[tokens[1]] = tokens[2]
            order.append((tokens[0], tokens[1]))
        elif tokens[0] == "Leave":
            order.append((tokens[0], tokens[1]))
        else:
            user[tokens[1]] = tokens[2]
        
    for ret in order:
        nickname = user[ret[1]]
        if(ret[0] == "Enter"):
            answer.append(nickname+"님이 들어왔습니다.")
        else:
            answer.append(nickname+"님이 나갔습니다.")
    
    return answer