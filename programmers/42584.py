def solution(prices):
    answer = []
    
    for i in range(len(prices)):
        p = 0
        for j in range(i+1, len(prices)):
            if(prices[i] <= prices[j]): p += 1
            else:
                p += 1
                break
        answer.append(p)
        
    return answer