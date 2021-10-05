# 괜찮고, 아주 기본적인 그리디 문제였다! 행복행복
def solution(people, limit):
    answer = 0
    
    people = sorted(people)
    left = 0 
    right = len(people)-1
    
    while left <= right:
        total = people[right]
        
        if total + people[left] <= limit:
            left += 1
        right -= 1
        answer += 1
    return answer