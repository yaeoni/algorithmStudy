
def solution(s):
    stack = []
    
    for c in s:
        if c == ')':
            if len(stack) == 0: return False
            stack.pop()
        else:
            stack.append(c)
    if len(stack) == 0 : return True
    return False