"""
연속된 자연수들로 n을 표현 방법 수(자기 자신 포함)

------------------ 첫번째 생각 ------------------
- 완전탐색을 한다면? 개수가 1개일때, 2개일때,,, 하나하나 집기엔 너무 오래걸리지않나(자릿수만큼 for문반복)
- 우선 몇 가지 경우를 더 써보게씀!
    1 = 1
    2 = 2
    3 = 1+2, 3
    4 = 4
    5 = 2+3, 5
    6 = 1+2+3, 6
    7 = 3+4, 7
    8 = 8 
    9 = 2+3+4, 4+5, 9
    ... 자기자신 제외하고 최대로 나올 수 있는 숫자는 반띵값 +1 ~연속으로 크게되면 n보다 큰값이 나올테니깐
    
- 뭔가 쪼개~는 방법은 아닌 것 같음ㅠ 맞나?

- 약간 생각한거 = 1,2,3,4 ... 하나하나 시작점으로 설정해서 n이되면 좋고, 넘으면 그만하고
        => 반띵한 값을 돌면서 해당 값에 위치한 곳에 매번 더해주기 (1, 1+2, 1+2+3,,) 하다가 만들어야할 자연수 만나면
            count 세어주기 / 자기자신 count+1 해주기
            => 테케 통과 but 시간초과!!! => 이유는 넘으면 할 필요가 없는데 매번 끝까지 가서 그랬어..
            
    ~ 시간초과 해결 할 수 있는 법 찾아요
    ~ 와.완전탐색인데 쉬발 나는 왜 안돼1!!! 와,,, 난 왜..나는 왜 시간초관데..걍하면되나봐 하.... 너무어렵게생각해서..
    
"""
# 맞은 풀이
def solution(n):
    answer = 1
    
    biggest = int(n*0.5) +1
    
    for i in range(1, biggest+1):
        sum = 0
        for j in range(i, n+1):
            if(sum == n):
                answer+=1
                break
            elif(sum > n):
                break
            else:
                sum += j
                
    
    return answer

# 틀린 풀이 ->> 시간초과. 주어진 n 넘으면 더이상 계산 안하면 되는데, 얘는 항상 해주니까 나나보다 쉬부루 ㅠ
def solution(n):
    answer = 1
    
    candidate = [0]*(int(n*(0.5))+2)
    
    # len(candidate)를 돌면서, 0~i 에 더해주기 / 매번 n의 값과 같은지 확인하기
    # 이넘이 틀린건 넘으면 candidate 더이상 안드가도 되는데, range 범위를 바꿔줄 수 없어서 그런거다.
    for i in range(1, len(candidate)):
        for j in range(1,i+1):
            candidate[j] += i
            if(candidate[j]==n):
                answer +=1
            #print(i, ", ",j," : ", candidate)
    return answer