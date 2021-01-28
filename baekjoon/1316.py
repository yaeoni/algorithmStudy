# group 단어인지 true, false로 리턴하기
# !문자의 연속성! 체크
def isGroup(word):
    word = list(word)

    temp = None
    child = {}

    for i, char in enumerate(word):
        if i == 0 :
            temp = char
            child[temp] = 0
        else:
            # 같지 않을 때 = 연속적이지 않을 때
            if temp != char:
                if char in child:
                    child[char] += 1
                else:
                    child[char] = 0
                temp = char

    for value in child.values():
        if(value != 0):
            return False

    return True
        
test = int(input())

ans = 0

for _ in range(test):
    word = input()

    if(isGroup(word)):
        ans+=1

print(ans)

