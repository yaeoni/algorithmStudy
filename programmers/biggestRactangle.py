"""
- 이전번에 풀었던 그 bfs, dfs의 문제 같은데 (아파트 단지 어쩌구 있잖아)
- 아파트 단지 제일 큰거 리턴인데, 그걸 정사각형 버전으로 / 대신 값은 하나만!?

? 정사각형의 조건을 어떻게 세워야할지 모르겠다. 정사각형의 조건... 
    = 가로 세로 길이 같아야하고, 그 안이 다 1로 채워져있어야함

! bfs로 푸는게 아니었따.!!!!!!!! 슬프다!!

----- 풀이방법 -----
- 모든 위치 돌면서, 만들 수 있는 정사각형을 찾기

1. 완전탐색 : 3중 포문(1찾고(2), 만들 수 있는 정사각형 찾고(1))
2. ** 동적 계획법 ** : 현재의 위치에서 만들 수 있는 최대 크기 정사각형 한 별 길이 저장!

- 왼쪽 위->오른쪽 아래로 진행하며 정사각형 계산해나감(= 인덱싱 위한 2중 포문) = 맨 윗줄, 맨 왼쪽 고정
- 정사각형이다 = 주위의 값(왼쪽 위,오른쪽 위, 왼쪽)들이 같은 값을 가지고 있다.(1이상)

- dp라는 배열을 따로 만들지 않아도, 기존 board위에다가 연산해도 상관이 없다. 그러면 dp 초기화가 필요 없겠ㅈㅣ?

"""

def solution(board):
    answer = 0
    
    row = len(board)
    col = len(board[0])
    
    # 들린 곳 표시
    dp = [[0]*(col) for _ in range(row)]
    
    # 맨 윗 줄
    dp[0] = board[0]
    # 맨 왼쪽
    for i in range(1, row):
        dp[i][0] = board[i][0]
        
    for i in range(1, row):
        for j in range(1, col):
            # 해당 값이 1일 때 주변 값을 확인하기
            # 주위의 값 중 가장 최소값에 + 1(0이어도 해당 값이 1이니깐, 1로 세팅이 되는거지)
            if(board[i][j]==1):
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) +1
                
    # 최대 넓이 구하기, 해당 배열에서 최대값 뽑아서 비교하는 방식 사용!
    for i in range(row):
        temp = max(dp[i])
        answer = max(temp, answer)
        
    # 넓이를 리턴해야하니깐!
    return answer**2