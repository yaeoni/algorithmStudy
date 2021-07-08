"""
[구하고자 하는 것]
BST에서 preorder 주어졌을 때 postorder 구하기

[생각]
- 우선 BST 표현을 코드로,, 배열로? 링리로?
- 전위 값 받고 후위로 어떻게 ? 전환할까 ?! ,,감도 안잡히는디
- 음,,, 모르겠는디,,,,ㅇㅁ,,,ㅁ,ㅇㅏ예모르겠는디? 10분만 더 생각해봄

- 입력으로 주어지는 값을 어떻게 받아야할 지 모르겠는디? 머냐
ex)
Root       left          right
50    30 24 5 28 45  | 98 52 60
     Root  l     r    Root  l

이 방식을 활용해서 배열 형식 이진트리 만든담에 후위 순회하기(?)

- 재귀로 잘 짜고싶은데 좀 어렵구만?
- 배열로 만들면 안될거같은데? 비어있는 곳 때문ㅇ ㅔ 

[답 봤다!]
- 입력 값 받기 -> try except로 오류 터지면 break 하도록 한다.
- 전위 순회에서 직접 후위 순회를 찍는 방법을 사용
- 분석은 나쁘지 않게 한 것 같은데 또 넘 어렵게 생각한 부분도 있는듯
- 어차피 트리를 만들었으면 시간 초과가 났을것이ㄷ ㅏ !!

[순회 트리 특]
- 각 특징 이용해 "루트" 뽑기(출력) -> 함수 인자로 시작, 끝 인덱스 넘기기
- start, end가 역전 시에 return 
"""
import sys
sys.setrecursionlimit(10 ** 6) # 파이썬 재귀 깊이는 수동으로 늘려줘야함, default 1000

pre = []
def printPostOrder(start, end):
    if(start > end):
        return

    root = pre[start]

    idx = start + 1

    # root 이후부터 커지는 지점 찾아 왼쪽 / 오른쪽 서브트리 나누기
    while idx <= end:
        if pre[idx] > root:
            break
        idx += 1

    printPostOrder(start+1, idx-1)
    printPostOrder(idx, end)

    print(root) # post order니까 루트 출력은 마지막에!

if __name__ == "__main__":
    while(1):
        try:
            pre.append(int(sys.stdin.readline()))
        except:
            break

    printPostOrder(0, len(pre)-1)