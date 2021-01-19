
t = input()
n,m = map(int, input().split())

ary = list(map(int, input().split()))

dp = []
idx = 0 
for i in range(n):
    dp.append(ary[idx : idx+m])
    idx += m

for i in range(1, m):
    for j in range(n):
        # 왼쪽 위 값
        if j == 0 : # 0번째 행은 왼쪽 위 값이 없다.
            left_up = 0 
        else:
            left_up = dp[j-1][i-1]
        
        # 왼쪽 아래
        if j == n-1 :# n-1 번째 행은 왼쪽 위 값이 없다.(마지막 줄)
            left_down = 0
        else:
            left_down = dp[j+1][j+1]
        
        left = dp[j][i-1]

        dp[j][i] = dp[j][i] + max(left_up, left_down, left)

# 시작점이 각 행의 어느번째부터든 갈 수 있었으니까 그중에 가장 큰거로 택하게끔!
result = 0

for i in range(n):
    result = max(result, dp[i][m-1])

print(result)