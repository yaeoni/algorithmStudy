"""
# 아 이게 생각할게 좀 있었구려? 정말 주어진 과정 그대로 진행하나요
0. 입력과 dict에서 일치하는 가장 긴 문자열 ans추가
1. 한글자만 더해서 dict에 추가

- 에러핸들링 : 맨 끝의 경우,, 맨 끝인데, 이미 사전에 있는 경우를 노가다로 잡아줬다. 솔직히 잘 짠 것 같지는 않다..
"""

# 사전에서 주어진 문자열에 없는 가장 짧은 문자열을 리턴한다. / 끝 인덱스와 함께
# 입력 : 문자열, 시작인덱스, 사전
def longest(msg, start, dict):
    flag = True
    idx = start

    temp = msg[idx]
    
    count = 0
    while(idx != len(msg)-1):
    #while(idx != len(msg)-1):
        if(temp in dict):
            idx += 1
            temp += msg[idx]
            #if(idx == len(msg)-1):
            #    print("End!", temp)
        else:
            break

    return temp, idx

def solution(msg):
    answer = []
    # 사전 초기화
    dict = {"A":1, "B":2, "C":3, "D":4, "E":5,
            "F":6, "G":7, "H":8, "I":9, "J":10,
            "K":11, "L":12, "M":13, "N":14, "O":15,
            "P":16, "Q":17, "R":18, "S":19, "T":20, 
            "U":21, "V":22, "W":23, "X":24, "Y":25, "Z":26
            }
    num = 27
    start = 0
    
    count = 0
    #while(count < 17):
    
    # 사전에 없는 가장 긴 문자열 반환
    while(True):
        word, end = longest(msg, start, dict)

        if(start==end):
            temp = msg[start:]
            answer.append(dict[temp])
            #print("word len zero", msg[start:])
            break
        else:
            if(word not in dict):
                dict[word] = num
                num+=1

                answer.append(dict[msg[start:end]])

                #print("answer :",msg[start:end],dict[msg[start:end]], "Add: ",word,dict[word])
            else:
                answer.append(dict[word])
                break
        start = end
        count += 1

    print(answer)
    return answer

