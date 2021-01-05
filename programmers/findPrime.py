from itertools import permutations

def solution(numbers):
    answer = 0
    
    a = set()
    
    # len(numbers) = 개수가 3개까지 택할 수 있다.
    for i in range(len(numbers)):
        
        # a에 계속 넣어주되, 중복 허용 안하기 = 합집합 기호 사용
        a |= set(map(int, (map("".join, permutations(list(numbers), i+1)))))
        
    # 0, 1 은 제외    
    a -= set(range(0, 2))
    
    # 가장 큰 수의 제곱근을 구해서 그 수 +1 까지 나열
    for i in range(2, int(max(a) ** 0.5)+1):
        
        #에라토스테네스의 체를 이용해 소수 제거
        # i*2부터 배수들 계속 빼주기
        a -= set(range(i*2, max(a)+1, i))
        
    return len(a)