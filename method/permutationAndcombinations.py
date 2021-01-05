# 순열
def permutation(arr, r):

    arr = sorted(arr) # 출력 이쁘게 정렬

    # i번째의 값을 썼는지 안썼는지 저장하는 용도. (중복 방지)
    # 0으로 초기화 시켜놓고 쓰면 1로 바꿈!
    used = [0 for _ in range(len(arr))]

    # 실제 순열을 만드는 함수
    def generate(chosen, used):

        # 2. 개수가 맞으면 출력
        if len(chosen) == r:
            print(chosen)
            return
	 
	# 3. used[i] == 0 일 때 chosen에 추가해주고, 1로 바꾸고 다시 generate 함수로
    # generate 돌고 나서는 다시 Uncheck 필요
   
        for i in range(len(arr)):
             # 중복되는 부분 없애기 = 조건 추가하기
             # 현재 원소가 정렬되어있기 때문에 가능!
            if not used[i] and ( i == 0 or arr[i-1] != arr[i] or used[i-1]):
                chosen.append(arr[i])
                used[i] = 1
                generate(chosen, used)
                used[i] = 0
                chosen.pop()
    generate([], used)

permutation('ABCD', 2)
permutation([1, 2, 3, 4, 5], 3)

# 조합
def combination(arr, r):
    # 1.
    arr = sorted(arr)

    # 2.
    def generate(chosen):
        if len(chosen) == r:
            print(chosen)
            return

    	# 3. 시작 지점을 chosen에 저장된 마지막 값으로  = 조합은 순서를 고려하지 않는다.
        start = arr.index(chosen[-1]) + 1 if chosen else 0

        for nxt in range(start, len(arr)):
            # 중복 제거
            if used[nxt] == 0 and (nxt == 0 or arr[nxt-1] != arr[nxt] or used[nxt-1]):
                chosen.append(arr[nxt])
                generate(chosen)
                chosen.pop()
    generate([])

combination('ABCDE', 2)
combination([1, 2, 3, 4, 5], 3)