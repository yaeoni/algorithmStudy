def solution(people, limit):
    answer = 0
    people.sort();
    
    canCarry = 0
    
    low = 0
    high = len(people)-1
    
    while(1):
        
        # 탈출조건이나, 엇갈린 경우는 이미 answer에 경우가 들어갔고, 같은 경우 (혼자 타는 경우)를 추가해줘야함
        if(low >= high):
            if(low == high):
                answer+=1
            break
            
        carry = people[low] + people[high]
        if(carry <= limit):
            low += 1 
            high -= 1
        else:
            high -=1   
        
        answer +=1
    
    
    return answer