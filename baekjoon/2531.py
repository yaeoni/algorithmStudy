"""
- 벨트 위엔 같은 종류 초밥 둘 이상 가능
[이벤트]
- 1.한 위치부터 k개의 접시를 연속해서 먹을 때 할인된 가격 제공
- 2. 1 행사 참여 시 무료 초밥 하나(없으면 만들어서 줌)

[요구사항]
- 손님이 먹을 수 있는 초밥 가짓수의 최댓값

[풀이 과정]
- "회전" 초밥 이라는 점!
- dict 활용해서 가장 많은 케이스 포함하는 경우 찾기(무료 제공은 카운트를 하지말자)
- "임의의 한 위치"부터 k개 접시

예시 과정 따라가기
- 한바퀴 돌면서 몇 가지의 종류가 있는지 확인하기
- 초밥의 가짓수는 왜 줬을까 
- 추가 초밥을 "추가로 무료료!!" 주는건데.. 사실 가짓수는 상관없지않지.ㅇㅁ..가짓수라..
- 지금 하는 방식 말고, 먹을 수 있는 가짓수부터 가능 케이스를 찾기,,? 멀라

[답]
- 무료로 먹을 수 있는 초밥을 추가해놓자 (로직 자체는 맞는 것 같은데, 핸들링을 잘못한 것 같다.)
"""
import sys
from collections import defaultdict
if __name__ == "__main__":
    n, d, k, c = map(int, sys.stdin.readline().split())
    
    belt = []
    for _ in range(n):
        belt.append(int(sys.stdin.readline()))

    left, right = 0, k-1
    cType = {} # c 제외하고 넣기

    cType[c] = 1
    for i in range(k):
        if(belt[i] not in cType):
            cType[belt[i]] = 1
        else:
            cType[belt[i]] += 1

    cnt = len(cType)

    for left in range(n):
        right = (left+k)%n
        cType[belt[left]] -= 1

        if cType[belt[left]] == 0:
            del cType[belt[left]]
        
        if belt[right] not in cType:
            cType[belt[right]] = 0
        cType[belt[right]] += 1

        cnt = max(cnt, len(cType))
        #print(cType)
    print(cnt)