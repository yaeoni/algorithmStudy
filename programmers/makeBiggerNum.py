def solution(number, k):
    collected = []
  
    for i, num in enumerate(number):
        # 마지막 원소와의 (계속적인) 비교
        while len(collected) > 0 and collected[-1] < num and k > 0:
            collected.pop()
            k -= 1
        # 더이상 뺄 수 없을 때 나머지 다 넣어주기
        if k == 0:
            collected += list(number[i:])
            break    
            
        collected.append(num)
    #만에 하나 빼진 것이 없다면 ex) 98765, 2 일 때 987로 다 담아지고, 아직 2개가 빼지지 않은 상태라서.
    if k > 0:
        collected = collected[:-k] 
        
    answer = ''.join(collected)
    return answer