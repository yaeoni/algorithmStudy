# 파이썬에서 리턴 할 때에는 return dp[n] = tile(n-1) + 2*tile(n-2) 가 안되는걸까?

n = int(input())

dp = [0, 1, 3]

def tile(n):
    if n == 1 : return 1
    elif n == 2 : return 3
    else:
        for i in range(3, n+1):
            dp.append(dp[i-1] + 2*dp[i-2])
    print(dp[n]%10007)

tile(n)