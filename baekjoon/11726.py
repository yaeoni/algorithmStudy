n = int(input())
dp =[0]*(n+1)

def tile(n):
    if n <= 3 : return n
    else:
        dp[1] = 1
        dp[2] = 2
        
        for i in range(3, n+1):
            dp[i] = dp[i-1] +dp[i-2]
        
        return dp[n] 

answer = tile(n)
print(answer % 10007)