def solution(s):
    answer = len(s)
    
    copy = s[:]
    # i == 몇 개씩 자를 것인가
    for i in range(1, len(s)-1):

        count = 1
        tempWord = copy[0:i]
        copy = copy[i:]
        word = ""
        
        while(1):
            #끝까지 다 갔을 때 break
            if(len(tempWord) < i):
                word += tempWord
                break
                
            #잘린 문자열과 이전 문자열이 같으면
            if(tempWord == copy[0:i]):
                count += 1
            else:
                if(count !=1):
                    word += str(count)+tempWord
                    count = 1
                else:
                    word += tempWord
                    
                tempWord = copy[0:i]
                    
            copy = copy[i:]
        
        if(answer > len(word)):
            answer = len(word)
        copy = s[:]
            
    return answer


