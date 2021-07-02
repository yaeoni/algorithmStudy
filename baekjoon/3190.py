"""
deque 공부의 예제!
"자기자신의 몸과 부딪히면" 이라는 종료조건이 있기에 뱀 길이와 위치를 기억해야한다.

- 시작시간으로부터 x초가 끝난 뒤 상황이 주어짐(최대 x초에 끝남.)
- 좌, 우 방향 "회전"?!, 전환만 하는거지 나아가는건 아냐 ** 대칭 활용
- 방향 전환을 너무 어렵게 생각한 것 같다 => 맞긴 맞았는데 다시 복습을 해야하는데 힘들ㄷ..ㅏ

* 리스트 범위 벗어나는 것 & 주어진 사과는 배열에 넣을 때엔 -1씩 해줘야한다는 것 & 문제 flow 대로 코드 짜기
"""
from sys import stdin
from collections import deque

def leftLoate(direction):
    if(direction[0] != 0):
        temp = direction[0]
        direction[0] = direction[1]
        direction[1] = temp
    else:
        temp = -direction[0]
        direction[0] = -direction[1]
        direction[1] = temp


    return direction

def rightLoate(direction):
    if(direction[0] != 0):
        temp = -direction[0]
        direction[0] = -direction[1]
        direction[1] = temp
    else:
        temp = direction[0]
        direction[0] = direction[1]
        direction[1] = temp


    return direction

if __name__ == '__main__':
    # size, num of apple
    n, k = int(stdin.readline()), int(stdin.readline())
    
    board = [[0]*n for _ in range(n)]

    # location of apple
    for _ in range(k):
        row, col = map(int, stdin.readline().split())
        board[row-1][col-1] = 1

    # snake's path information
    l = int(stdin.readline())

    # (start time, direction)
    # L = left, D = right
    path = deque()

    for _ in range(l):
       path.append(stdin.readline().split())
    
    snake = deque()
    snake.append([0,0])

    # end time
    ret = 0
    
    # init -> right 
    direction = [0,1]
    for _ in range(10000):
        
        ret+=1
        cur = snake[len(snake)-1]

        newX = cur[0] + direction[0]
        newY = cur[1] + direction[1]

        if(newX < 0 or newY < 0 or newX >= n or newY >= n):
            break
        elif([newX, newY] in snake):
            break
        
         # there is an apple
        if(board[newX][newY]==1):
            board[newX][newY] = 0
        else:
            snake.popleft()

        snake.append([newX, newY])

        if(len(path) != 0 and int(path[0][0]) == ret):
            p = path.popleft()
            if(p[1]=="L"):
                direction = leftLoate(direction)
            else:
                direction = rightLoate(direction)
    print(ret)