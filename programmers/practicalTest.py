from functools import cmp_to_key
def compare(x, y):
    if(x[1] < y[1]):
        return 1
    elif(x[1] > y[1]):
        return -1
    else:
        if(x[0]<y[0]):
            return -1
        elif(x[0]>y[0]):
            return 1
        else:
            return 0
    

def solution(answers):
    answer = []
    
    one = "12345"
    two = "21232425"
    three = "3311224455"
    
    oneIdx = 0
    twoIdx = 0
    threeIdx = 0
    
    #temp = [[1,0],[2,0],[3,0]]
    score = [0, 0, 0]
    
    for ans in answers:
        
        if(len(one) <= oneIdx):
            oneIdx = 0
        if(len(two) <= twoIdx):
            twoIdx = 0
        if(len(three) <= threeIdx):
            threeIdx = 0
            
        if(ans== int(one[oneIdx])):
            #temp[0][1] += 1
            score[0] += 1
        if(ans==int(two[twoIdx])):
            #temp[1][1] += 1
            score[1] += 1
        if(ans==int(three[threeIdx])):
            #temp[2][1] += 1
            score[2] += 1
            
        oneIdx += 1
        twoIdx += 1
        threeIdx += 1
    
    # 가장 많은 문제를 맞춘 사람이 "누구"인지 / 동점이면 오름차순으로
    # 이렇게 쉬운 방법이..가장 큰수와 계속 비교하면 된다!
    for i, v in enumerate(score):
        if(v == max(score)):
            answer.append(i+1)
    """
    temp = sorted(temp, key=cmp_to_key(compare))
    
    max = temp[0][1]
    for item in temp:
        if item[1] == 0 :
            break
        else:
            if not answer:
                answer.append(item[0])
            else:
                
                if max == item[1]:
                    answer.append(item[0])
            
    """
    return answer