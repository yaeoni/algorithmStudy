# 직접 lower_bound 구현하기 (이진 탐색 이용)

# lower_bound : 정렬된 배열 속에서 찾고자하는 값(target)보다 그 "이상"이 처음 나타난 위치

def lower_bound(nums, target):
    left, right = 0, len(nums)
    
    while left < right :
        mid = (left + right)//2
        
        if nums[mid] == target:
            right = mid
        elif nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid
    
    return right
            

def solution(info, query):
    answer = []

    dic = dict()
    
    # case 생성
    for value in info:
        tokens = value.split(" ")
        
        # - 와의 조합 만들기
        selection = [["-", "-"] for _ in range(4)]
        score = int(tokens[4])
        
        for idx, s in enumerate(selection):
            s[0] = tokens[idx]
        
        for i in selection[0]:
            t1 = ""
            t2 = ""
            t3 = ""
            t4 = ""
            
            t1 = i
            for j in selection[1]:
                t2 = j
                for k in selection[2]:
                    t3 = k
                    for l in selection[3]:
                        t4 = l
                        
                        key = t1+t2+t3+t4
                        if key not in dic:
                            dic[key] = [score]
                        else:
                            dic[key].append(score)

    # 점수 정렬
    for key in dic:
        value = dic[key]
        value = sorted(value)
        dic[key] = value
        
    # query에 해당하는 key를 가지고(파싱 필요), 해당 점수 위인 개수 리턴
    for value in (query):
        tokens = value.split(" and ")
        temp = tokens[3].split(" ")
        tokens[3] = temp[0]
        score = int(temp[1])
        
        key = ""
        for v in tokens:
            key += v
        
        ans = 0
        if key in dic:
            ans = len(dic[key])- lower_bound(dic[key], score)
        
        answer.append(ans)
    return answer