from itertools import combinations

def solution(relation):
    answer = 0
    col = [ i for i in range(len(relation[0]))]
    
    unique = {}
    for i in range(1, len(col)+1):
        # 선택 가능한 컬럼 조합 
        comb = list(combinations(col, i))
        
        # 유일성 판별 => 해당 컬럼의 값을 이어 붙인 후 unique를 판별한다.

        for c in comb:
            
            record = {}
            
            for r in relation:
                temp = ""   
                for key in c:
                    temp += r[key]
                
                if temp not in record:
                    record[temp] = 0
                else:
                    break
                    
            if(len(record)== len(relation)):
                # 최소성 판별 <- "모든 요소"가 찐 후보키에 들어가있으면 안되는거임.
                # 따라서 count를 두고 찐 후보키의 개수만큼 counting되면 최소성 만족 불가
                flag = True
                
                for u in unique:
                    count = 0
                    for val in c:
                        if val in u:
                            count += 1
                            
                    if(count == len(u)):
                        flag = False
                        break
                        
                if(flag):
                    unique[c]= 0
                
    return len(unique)