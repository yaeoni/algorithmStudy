# 똑같은 로직을 짜는데 왜 무한 루프일까,, 후,,
# ..리얼 바보.. board가 " " 로 바꿔주어ㅑ지,,
def solution(m, n, strings):
    answer = 0    
    
    board = []
    
    for s in strings:
        temp = []
        for c in s:
            temp.append(c)
        board.append(temp)

    flag = True

    while(flag):
        arr = [ [False]*n for _ in range(m)]
        flag = False
        
        for i in range(m-1):
            for j in range(n-1):
                
                if(board[i][j] == " "): continue
                
                target = board[i][j]
                
                if(target == board[i][j+1] and target == board[i+1][j] and target == board[i+1][j+1]):
                    arr[i][j] = True
                    arr[i][j+1] = True
                    arr[i+1][j] = True
                    arr[i+1][j+1] = True
                    flag = True
                    
        
        for i in range(m):
            for j in range(n):
                if(arr[i][j]):
                    answer+=1
                    for k in range(i-1, -1, -1):
                        board[k+1][j] = board[k][j]
                        board[k][j] = ' '
        
    return answer