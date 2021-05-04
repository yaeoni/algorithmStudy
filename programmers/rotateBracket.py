def solution(s):
    answer = 0
    
    
    for i in range(0, len(s)):
        flag = True
        x = s[i:]+s[:i]
        stack = []
        for val in x:
            if(val == "[" or val == "(" or val == "{"):
                stack.append(val)
            elif(val == "]"):
                if(stack and stack.pop() == "["):
                    continue
                else:
                    flag = False
                    break
            elif(val==")"):
                if(stack and stack.pop() == "("):
                    continue
                else:
                    flag = False
                    break
            elif(val=="}"):
                if(stack and stack.pop() == "{"):
                    continue
                else:
                    flag = False
                    break        
        if(flag == True and len(stack) == 0):
            answer += 1
    return answers