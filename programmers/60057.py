def solution(s):
    answer = len(s)
    
    for unit in range(1, int(len(s)/2) + 1):
        # initialize
        compNum = 1
        token = s[0:unit]
        modified = ""
        
        for i in range(unit, len(s), unit):
            temp = s[i:i+unit]
            
            if(token == temp): compNum += 1
            else:
                if(compNum != 1): modified += str(compNum)
                
                modified += token
                token = temp
                compNum = 1
    
        if(compNum != 1): modified += str(compNum)
        modified += temp
        
        answer = min(answer, len(modified))
    return answer