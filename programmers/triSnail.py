"""
---------- 처음 생각 -----------
- 아무래도 수학적 규칙을 찾는 것 같은데.. 수학적 머리가 안되니 원:(

- 전체 배열의 길이 = ( n*(n+1) ) / 2 = 끝 값.
    ~ 배열을 미리 세워놓고, 값을 채워넣으려는 방향으로 가려했따. 
    
#  세모의 양 꼭짓점 값을 정해두고(넣어두고) 나머지들 채우기..? 양 끝 점 사이 간격이 n-2-2i 같은디
    -> 이러면 겉에 면은 되어도, 안에 얘들을 채우는게 감이 안잡힘
    
~흠 다시돌아와서 생각해도 모르겠으면 그냥 답 봐버리겠따

-------- 답안 이해하기 ----------
- 한 쪽으로 밀어서 직각삼각형으로 생각하기 / x와 y값이 점차 증가하는 직.삼 모양
- 방향 : 아래, 오른쪽, (대각선)위 의 반복

    이중 포문을 돌면서 방향을 아래와 같이 정의하는데, 아직 여기가 이해가 안됨
    => 방향 ) 아래 = 나머지 0 / x += 1
             오른쪽 = 나머지 1 / y +=1
             위 = 나머지 1 / x-= 1 y-=1
ex) n = 4

아래 -> 4
오른쪽 -> 3
위 -> 2
아래 -> 1
=> 한 변을 지날 때마다 쓰이는 수가 1씩 적어짐

1
2 9
3 10 8
4 5  6 7


0. 삼각 달팽이 값 넣을 2차원 배열 초기화 = 0
1. 좌표값 / 첫 시작숫자(1) 초기화
2. 값을 넣을 이중포문 작성 ( n -> n-1 -> n-2 개씩 저장해야함)
3. 2차원 배열을 1차원배열로 
"""
def solution(n):
    answer = []
    
    triSnail = [ [0]*n for _ in range(n)]
    x, y = -1, 0
    num = 1
    
    for i in range(n):
        for j in range(i, n):
            
            if(i%3==0):
                x += 1
            elif(i%3==1):
                y += 1
            elif(i%3==2):
                x -= 1
                y -= 1
            
            triSnail[x][y] = num
            num += 1
    for item in triSnail:
        for num in item:
            if(num != 0):
                answer.append(num)
    return answer