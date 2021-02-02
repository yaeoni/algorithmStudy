# 파이썬에서의 투포인터 구현을 어떻게 해야하는지 살짝 감이 안오는중
# 항상 느끼는거지만, 범위 체크가 굉장히 중요한 것 같다.
# 1차 시도 -> 실패 // break 문의 조건을 잘 못 걸은 것 같음.
# 2차 시도 -> 실패 // break 문 잘못걸은거,, end가 끝만가면 안되지.. 음 생각중! start가 끝으로 가는 경우로 해야함!
# 왜인지를 모르겠어........

n, m = map(int, input().split())
ary = list(map(int, input().split()))

start = 0
end = 0

sumVal = ary[start]
ans = 0
while(True):
    #print("sum",sumVal, "start, end", start, end)
    if(sumVal == m):
        ans += 1
    if(end == len(ary)-1):
        break
    
    # 처음부터 m보다 큰 경우(start, end가 같은데..)
    if(start==end and sumVal > m and end+1<len(ary)):
        start += 1
        end += 1
        sumVal = ary[start]
    # 부분 요소의 합이 m 보다 적으면 end를 늘려서 요소를 더해준다.
    # 범위 체크
    elif(sumVal < m and end+1 < len(ary)):
        end += 1
        sumVal += ary[end]
    # 부분 요소의 합이 m 보다 크면 start를 늘리고 요소를 빼준다.
    else:
        sumVal -= ary[start]
        start += 1

print(ans)