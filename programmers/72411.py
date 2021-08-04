"""
파이썬 내에 조합 구하는게 있었는디 -> itertools에서 import 해오기!
주어진 메뉴 스트링은 순서대로 나와있지 않음! sort 주의하기
"""

from itertools import combinations

def solution(orders, course):
    answer = []

    for count in course:
        dic = {}

        for data in orders:
            # count보다 길이 짧으면 조합 어차피 안나옴 -> continue
            if(len(data) < count): continue

            data = sorted(data)
            combList = [ ''.join(temp) for temp in list(combinations(data, count))]
            
            for comb in combList:
                if comb in dic: dic[comb] += 1
                else: dic[comb] = 1
        
        # dic 속 value 값 기준 정렬
        order = sorted(dic.items(), key=lambda x: x[1], reverse=True)
        if(order):
            max = order[0][1]
            if(max != 1):
                for value, c in order:
                    if(max == c):
                        answer.append(value)
            
        answer = sorted(answer)
    return answer