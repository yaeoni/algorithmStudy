# 다른 방향으로 회전시키기
def solution(rows, columns, queries):
    answer = []
    
    board = [[0]*columns for _ in range(rows)]
    num = 1
    for i in range(rows):
        for j in range(columns):
            board[i][j] = num
            num += 1
            
    for query in queries:
        x = query[0] -1
        y = query[1] -1
        xx = query[2] -1
        yy = query[3] -1
        
        temp = board[x][yy]
        minNum = temp
        
        for i in range(yy, y, -1):
            minNum = min(minNum, board[x][i])
            board[x][i] = board[x][i-1]
        
        for i in range(x, xx):
            minNum = min(minNum, board[i][y])
            board[i][y] = board[i+1][y]
            
        for i in range(y, yy):
            minNum = min(minNum, board[xx][i])
            board[xx][i] = board[xx][i+1]
            
        for i in range(xx, x, -1):
            minNum = min(minNum, board[i][yy])
            board[i][yy] = board[i-1][yy]
            
        board[x+1][yy] = temp
        
        answer.append(minNum)
        
    return answer