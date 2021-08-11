# bfs를 이용해 풀어보자
# queue이용

from collections import deque
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

# 깊이 2까지 체크한다는 것 빼먹지 말기!
# bfs에선 깊이때문에 하나의 큐에서 해결이 안된다 -> 하나의 좌표별 queue를 생성해야함.
def bfs(place, p):
    visited = [[False]*5 for _ in range(5)]
    deep = 0
    people = deque()
    people.append(p)
    
    while(people):
        # people queue의 한 턴을 다 소진해야 deep 을 1 늘릴 수 있음. 흑,, 이걸 왜했나했드만 ㄷ ㅏ 이유가 있었구나..
        print(len(people))
        for _ in range(len(people)):
            (x, y) = people.popleft()
            visited[x][y] = True

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if(nx < 0 or ny < 0 or nx >= 5 or ny >= 5 or visited[nx][ny]):
                    continue

                if place[nx][ny] == 'P':
                        return False
                elif place[nx][ny] == 'X':
                    continue
                else:
                    people.append((nx, ny))
        deep +=1
        if(deep == 2 or not people):
            return True
        
def solution(places):
    answer = []
    
    for place in places:
        people = deque()
        # bfs위한 좌표 집어넣기
        for i in range(5):
            for j in range(5):
                if place[i][j] == 'P':
                    people.append((i,j))
                    
        if len(people) == 0:
            answer.append(1)
            continue
        
        flag = True
        
        for p in people: # 하나의 P 좌표에 대해서 깊이 2까지 체크
            flag = bfs(place, p)
            if(flag == False):
                answer.append(0)
                break
        if flag == True:
            answer.append(1)
    return answer