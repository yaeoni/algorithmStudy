# DP 는 계쏙 피해왔는데,, 유형을 기억하는 느낌으로 해보자!
def solution(board):
    answer = board[0][0]
    
    r = len(board)
    c = len(board[0])
    
    for i in range(1, r):
        for j in range(1, c):
            if(board[i][j] == 1):
                board[i][j] = 1 + min(board[i-1][j-1], board[i-1][j], board[i][j-1])
                answer = max(answer, board[i][j])

    return answer * answer