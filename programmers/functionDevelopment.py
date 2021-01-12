# 완전탐색 생각은 매번 speeds더해가면서 계속 체크.
# 뒤에 있는 기능이 앞에 있는 기능이 배포되어야 배포 될 수 있음

# 계속 더해주고 앞에거 진도 완료되었을 때 뒤에거 까지 빼주기
def solution(progresses, speeds):
    answer = []
    progresses.reverse()
    speeds.reverse()
    

    while(progresses):
        # 맨 앞에 있는게 완료 되었는가?
        count = 0
        
        while(progresses):
            item = progresses.pop()
            if(item < 100):
                progresses.append(item)
                break
            else:
                speeds.pop()
                count +=1
                
        if(count > 0):
            answer.append(count)
        
        # speeds더해주기
        for i, num in reversed(list(enumerate(speeds))):
            progresses[i] += num
  
    return answer