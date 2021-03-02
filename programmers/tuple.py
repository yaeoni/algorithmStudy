"""
- 문자열이 주어짐 -> 파싱 필요
- 튜플!!은 정해진 순서가 있음!!! 그거까지 유추해야함 순서 유추를 어떻게하는데..
    => 문제에 집합표현을 어떻게 할 지 주어져 있네! 가장 많이 자주 나오는 순서대로임.. 헉 문제를 잘읽자
    => 규칙을 문제에서 더 찾을 수 있었따. 원소가 1개인 집합이 a1, 2개인 집합이 무족권 a1, a2..
    => 자른 배열들을 길ㅇ이 순서대로 나열 한 후 중복안된놈부터 넣으면된다. 하..~
------------------------ 1번째 생각 ------------------------
0. 앞 뒤 자르고
1. {}를 잘라서 안에 내용물 넣기, 를 기준으로 자르면 안되는게 안에 구성물임
    -> 20 과 같이 두 자리 수 처리를 못함!
2. 파이썬은 set처리하면 될듯! -> 가장 많이 나온 순으로

                    -생각 오류-

------------------------ 2번째 생각 ------------------------
0. 앞 뒤 자르고
1. {} 잘라서 내용물을 넣어야된다. , 를 기준으로
2. 가장 많이 나온 순으로 정렬을 때려야함. 비슷한걸 해봤던거같은데~ 
  => str to int는 map 이용해서 하고, 개수별 카운트는 sorted option으로 줄 수 있다!(와우!)
3. 이후 중복없이 하나하나 넣어주기(set은 unordered라 순서 보장을 안해주네!)

                    - 시간 초과 -
                    이유) 문자열 파싱을 너무 힘들게함
                    0. 앞 뒤 자름
                    1. {} 기준 자름
                    2. , 기준 자름
                    toooo many 였다.
                    
                    이유2) sorted와 중복불가 조건
                    
------------------------ 3번째 생각 ------------------------
- 어디서 가장 시간이 오래거릴ㄹ까
- map도 sorted도 한번씩 돌아야해서 그런가.. 효율적인 어떤 방법을 찾아야댐
- map을 최종본에만... answer에만.. 쉽다면서...

아!!! 뭔가 문자열을 다르게 파싱하는 방법을 생각했어야했다.
0. 맨 앞 맨 뒤 {{   }}을 잘라주고
1. },{  로 split 처리..와우!

2. sorted 방식 변화 ->sorted를 모든 원소에 대해서 할 필요가 없어지는거임!!
2-2. 따라서 map 처리를 할 필요도 없어짐! 아하!
"""

# 2번째 생각구현 ( 시간 초과 ㅎ )
def solution(s):
    answer = []
    
    s = s[1:len(s)-1]
    
    nums=[]
    relation = ""
    
    for temp in s:
        if(temp=="{"):
            continue
        elif(temp=="}"):
            if relation[0]==",":
                relation=relation[1:]
            nums.extend(relation.split(","))
            relation= ""
        else:
            relation += temp

    nums = sorted(nums, key=nums.count, reverse=True)
    
    for temp in nums:
        if temp not in answer:
            answer.append(temp)

    return list(map(int,answer))


# 바뀐버전 -> 문자열 파싱법 , 배열 순서대로 둬서 중복제거하면서 넣는 것. ( 위에 방법처럼 sorted를 모든 원소에 대해서 할 필요가 없어지는거임!!)
def solution(s):
    answer = []
    
    nums = []
    s= s[2:-2]

    token = s.split("},{")
    token= sorted(token, key=len)
    
    for item in token:
        temp = item.split(",")
        for num in temp:
            if int(num) not in answer:
                answer.append(int(num))
                
    return answer