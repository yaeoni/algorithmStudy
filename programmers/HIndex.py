def solution(citations):
    answer = 0
    citations.sort(reverse = True)
    
    for i, num in enumerate(citations):
        if(i==num): 
            return num
        elif(num < i):
            return i
        else:
            answer +=1 
    
    return answer