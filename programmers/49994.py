# 파이썬으로 4차원 배열만들기,, => for문 겹치는거를 잘 세워봅시다
def solution(dirs):
    answer = 0
    
    board = [[[[0 for _ in range(11)] for _ in range(11)] for _ in range(11)] for _ in range(11)]
    
    x = 5
    y = 5
    
    for dir in dirs:
        if dir == 'D':
            if x + 1 < 11:
                if board[x][y][x+1][y] != 1:
                    board[x][y][x+1][y] = 1
                    board[x+1][y][x][y] = 1
                    answer += 1
                x += 1
        elif dir == 'U':
            if x - 1 >= 0:
                if board[x][y][x-1][y] != 1:
                    board[x][y][x-1][y] = 1
                    board[x-1][y][x][y] = 1
                    answer += 1
                x -= 1
        elif dir == 'L':
            if y - 1 >= 0:
                if board[x][y][x][y-1] != 1:
                    board[x][y][x][y-1] = 1
                    board[x][y-1][x][y] = 1
                    answer += 1
                y -= 1
        elif dir == 'R':
            if y + 1 < 11:
                if board[x][y][x][y+1] != 1:
                    board[x][y][x][y+1] = 1
                    board[x][y+1][x][y] = 1
                    answer += 1
                y += 1

    return answer