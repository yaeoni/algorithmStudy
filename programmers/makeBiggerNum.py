# 혼자 푼 버전
# 한 번 지워주면 계속 지워줘야 한다!
# edge case에 대한 검사 혼자서 해보는 연습 하기! ( ex. 111, 2 => 1)
def solution(number, k):
    answer = 0
    
    ret = []
    
    number = list(number)
    size = len(number)-k
    idx = 0

    for num in number:
        if(k==0):
            break
        else:
            while(ret and ret[len(ret)-1] < num and k != 0):
                k-=1
                ret.pop()
                
            ret.append(num)  
        idx +=1
    
    # 아직 k 값이 남았다. = 맨 뒤에서 K개수만큼 빼주면 된다. 
    if(len(ret) != size):
        if(k!=0):
            ret = ret[:-k]
        else:
            ret += number[idx:]
    return ('').join(ret)

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
    #만에 하나 빼진 것이 없다면 ex) 98765, 2 일 때 98765로 다 담아지고, 아직 2개가 빼지지 않은 상태라서.
    if k > 0:
        collected = collected[:-k] 
        
    answer = ''.join(collected)
    return answer

