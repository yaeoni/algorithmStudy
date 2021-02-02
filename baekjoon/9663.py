n = int(input())
ans = 0

def nqueen(case, N):
    global ans

    # 한 행에 퀸이 1개씩 존재하는 경우까지 도달했을 때
    if(len(case)==N):
        ans += 1
        return
    
    # 후보가 될 위치 배열(이 다음 퀸을 어디에 둘 지?)
    candidate = list(range(N))

    for i in range(len(case)):
        if case[i] in candidate: # 같은 열에 존재하는 애들 제외
            candidate.remove(case[i])

        dist = len(case) - i # 대각선에 위치한 요소
        # x좌표끼리, y좌표끼리 뺴서
        
        # 각 퀸들에 관한 대각선 위치들 지우기
        if case[i]+dist in candidate:
            candidate.remove(case[i]+dist)
        if case[i]-dist in candidate:
            candidate.remove(case[i]-dist)

    if candidate != []:
        for item in candidate:
            case.append(item)
            nqueen(case, N)
            case.pop() # 검사가 완료됐거나, candidate가 다 소진 되었을 때(더이상 갈 수 없을 때) pop() 시켜주는 것.
    else:
        return 
    
# 0번째 행이 0~n-1까지의 위치를 가진다고 가정할 때 back-tracking기법으로 답 구하기
for i in range(n):
    nqueen([i], n)

print(ans)