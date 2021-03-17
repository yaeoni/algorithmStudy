"""
while(빈 공간이 없을 때까지):
    - 2X2블록 찾기 -> 터뜨리기
    - 빈 공간 채우기

* 여기서 빈 공간 채우는 방법에서 막혔다.
    => 행과 열을 전환하고, 지워진 놈 개수만큼 옆으로 밀면 
        본래 보드에서 아래로 내려가는 효과를 준다 (그림그려보면 이해완료 / 그지같은..)

*** 배열 문제에서, 가끔은 배열을 회전하는 방법도 생각하자! / 그림도 그력가면서 휙후기
    
# zip
: 파라미터로 입력받은 iterable elements들을 순서대로 묶어주는 내장함수
: 파라미터 앞에 *을 붙이면 여러개의 iterable elements로 나누어진다. (=unzip)
"""

def getPop(b, n, m):
    # 2X2 좌표를 구해서 터뜨려줘야함 => 0 으로 전환
    pop_set = set()
    for i in range(0, n-1):
        for j in range(0, m-1):
            #같은 2X2 블록을 찾았소
            if(b[i][j] == b[i][j+1] == b[i+1][j] == b[i+1][j+1] != "-"):   
                pop_set |= set(((i,j), (i,j+1), (i+1, j), (i+1, j+1)))
                
    for i, j in pop_set:
        b[i][j] = 0
    
    # 빈 공간 채워주는 과정
    for i, row in enumerate(b):
        # 1줄 속 0의 개수를 세어서 "_" 배열을 만듬
        empty = ["-"]*row.count(0)
        
        b[i] = empty + [ block for block in row if block != 0 ]
        
    #print(b)
    #print("pop count", len(pop_set))
    return len(pop_set)

def solution(m, n, board):
    answer = 0
    
    # 문자열 배열을 하나씩 띄워서 배열로 만들기
    b = list(map(list,zip(*board)))

    while(True):
        pop = getPop(b, n, m)
        if pop == 0:
            return answer
        answer += pop
    return answer