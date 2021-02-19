# 파이썬에서의 투포인터 구현을 어떻게 해야하는지 살짝 감이 안오는중
# 항상 느끼는거지만, 범위 체크가 굉장히 중요한 것 같다.
# 1차 시도 -> 실패 // break 문의 조건을 잘 못 걸은 것 같음.
# 2차 시도 -> 실패 // break 문 잘못걸은거,, end가 끝만가면 안되지.. 음 생각중! start가 끝으로 가는 경우로 해야함!
# 왜인지를 모르겠어........ 알았따! end끝까지가면 너무 크고, start로 조절해줘야하는 경우 때문임!

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

# 다른 사람 풀이
ans = 0
lo, hi = 0, 1 # 애초부터 한 칸 옆에다가 설정
tmp = ary[lo]

while lo < n:
    if tmp==m:
        ans +=1
        temp -= ary[lo] # 경우의 수 더해주고 다음 케이스로 가자
        lo += 1

    # 범위 체크 ( break 문 ,, 난이게 왜있는건지 몰겠긴함. 끝까지 다 갔는데 m 보다 작으면 의미없긴하지!?!앟)
    if hi == n and tmp < m :
        break
    elif tmp < m :
        tmp += ary[hi]
        hi += 1
    elif tmp > m :
        tmp -= ary[lo]
        lo -= 1
