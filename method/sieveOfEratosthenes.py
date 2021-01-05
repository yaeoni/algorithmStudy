"""
에라토스테네스의 체 : 범위에서 합성수를 지우는 방식으로 소수를 찾는 방법. 
1. 1은 제거 
2. 지워지지 않은 수 중 제일 작은 2를 소수로 채택하고, 나머지 2의 배수를 모두 지운다. 
3. 지워지지 않은 수 중 제일 작은 3을 소수로 채택하고, 나머지 3의 배수를 모두 지운다. 
4. 지워지지 않은 수 중 제일 작은 5를 소수로 채택하고, 나머지 5의 배수를 모두 지운다. 
5. (반복)

* 특정한 수의 제곱근까지만 약수의 존재 여부를 검증하면 된다.
"""

def getPrime(n):
    # 체 초기화 = n개의 요소를 True로 설정
    sieve = [True] * n

    # 제곱근 까지만 약수 존재 여부 확인하면 된다.
    m = int(n**0.5)

    for i in range(2, m+1):
        if sieve[i] == True: # 첫 번째로 만나는 수는 소수 (이후 그 수의 배수들은 지워주는 방식)
            for j in range(i+i, n, i): # i 의 배수들을 체크하여 False
                sieve[j] = False
        
    # 소수들의 목록
    return [i for i in range(2, n) if sieve[i] == True]