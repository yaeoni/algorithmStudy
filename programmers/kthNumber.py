def solution(array, commands):
    answer = []
    
    
    for item in commands:
        start = item[0] - 1
        end = item[1]
        
        ary = array[start:end]
        ary.sort()
        
        answer.append(ary[item[2]-1])
    return answer