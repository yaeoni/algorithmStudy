def solution(name):
    answer = 0
    alpha = {"A":0, "B":1, "C":2, "D":3, "E":4, "F":5, "G":6,
            "H":7, "I":8, "J":9, "K":10, "L":11, "M":12, "N":13, "O":14,
            "P":15, "Q":16, "R":17, "S":18, "T":19, "U":20, "V":21,
            "W":22, "X":23, "Y":24, "Z":25}
    
    # change 배열에 최소 이동 횟수 저장
    change = []
    for temp in name:
        if(alpha[temp] <= 13):
            change.append(alpha[temp])
        else:
            change.append(25 - alpha[temp] +1)

    idx = 0
    
    while(1):
        answer += change[idx]
        change[idx] = 0 
        
        if sum(change) == 0: break
            
        left = 1
        right = 1
        
        while(change[idx + right]==0):
            right += 1
        while(change[idx - left]==0):
            left += 1
        
        # <= 면 안된다. 왜? ! 
        if left < right:
            idx -= left
            answer += left
        else:
            idx += right
            answer += right
            
        """
        # 잘 돌아가는 부분 
        if left >= right:
            idx += right
            answer += right
        else:
            idx -= left
            answer += left
        """
        
    return answer