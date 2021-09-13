global count
global result

count = 0
result = 0

def dfs(arr, word):
    global count
    global result
    ary = ['A', 'E', 'I', 'O', 'U']
    
    if arr:
        count += 1
        if word == ''.join(map(str, arr)):
            # string으로 join
            result = count
            return
    
    if len(arr) == 5: return
    
    for value in ary:
        arr.append(value)
        dfs(arr, word)
        arr.pop()

def solution(word):
    global count
    global result
    answer = 0
    dfs([], word)
    return result