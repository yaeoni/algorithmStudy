"""
- 해시로(딕셔너리로일단?) 최대 몇가지로 올 수 있는지 체크 ..(re개수 +1) / 기본적으론 1개
- re 개수 + 1 로만 판단해도 되는건진 잘 모르겠음 -> 예시를 잘 읽어보면 아님
- 애초에 re: 로 split하고, 해당 배열의 길이로 하면 되겠다.( 마지막 값을 key 값으로 !)

- 각 dict의 values들의 합은 최소 값이고 그 이상으로 예측하기만 하면 될 것 같은디
"""
import sys


if __name__ == "__main__":
    
    n, k = map(int, sys.stdin.readline().split())

    minAns = 0

    chains = {}
    for _ in range(k):
        chain = sys.stdin.readline().replace(' ','').split("Re:")

        if chain[-1] not in chains:
            chains[chain[-1]] = len(chain)
        else:
            chains[chain[-1]] = max(chains[chain[-1]],len(chain))
        
    for value in chains.values():
        minAns += value
    
    if(minAns <= n):
        print("YES")
    else:
        print("NO")