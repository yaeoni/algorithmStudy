# 내 생각 = 조합으로 7개 뽑아서, 먼저 100이 되면 끝내도록. 하지만 내가 구현한 조합은 모든 케이스를 다 구하며, 중간에 멈출 수가 없었다(재귀라서)
# itertools의 combinations 함수 쓰면 훨씬 빠를 듯~ 

ary = []

for _ in range(9):
    ary.append(int(input()))

case = []
# 이 놈은 말그대로, 정말 모든 경우의 수를 다 구하는 재귀형식으로 빠져서 중간에 답이 나와도 계속 도는게 문제임
# case 라는 global 변수에 모든 케이스 넣고, 거기서 100 되는 첫 번째 놈을 가지고오고싶은데, case에 왜 안담기는걸까? 왜 안담기지 이해가 안가네 이거는..
# chosen 이 바뀌면서 안에 들어있던 애들은 "복사본이 아닌거지" 그래서 싹 바뀌나봐, 마지막에 다 pop되어버리니까 그래서 없는 듯?
def generate(chosen, r):
    global case
    if(len(chosen)==r):
        temp = chosen[:]
        case.append(temp)
        
        return

    start = ary.index(chosen[-1]) +1 if chosen else 0 

    for idx in range(start, len(ary)):
        chosen.append(ary[idx])
        generate(chosen, r)
        chosen.pop()

generate([], 7)


for temp in case:
    if sum(temp)==100:
        temp.sort()
        for i in range(len(temp)):
            print(temp[i])

        break
