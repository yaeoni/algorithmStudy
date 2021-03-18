"""
- LRU -> Recently*** 오래전에 쓰인걸 교체한다야... 후..;;

* 시간의 업데이트. 어떻게 구현할 수 있을까 

과정)
1. cache에 있는가
2-1 없다 -> miss (5)
2-1-2 캐시가 비었는가? ㅇㅇ-> 넣기 / ㄴㄴ -> 가장 오래전에 쓰인놈과 교체
2-2 있다 -> hit (1)

필요 조건)
- 딕셔너리 -> 시간을 넣어야된다. 시간은 애매하니까 그냥 숫자를 넣도록하겠다 ^^; 
    -> count 형식으로 쓰일 때마다 +1
- 대소문자 구분 없이

# 딕셔너리에서 smallest value로 key 찾기 = min(dict, key=dict.get)

내 생각)
- 딕셔너리 개수 제한이 가능한가? len으로 하면 된다.

------------- 에러 -------------
- 45/100 나오는데, 테케가 다 통과하니 어떤걸 해봐야할지 모르겠음 ㅜ ~ 100 나오는 로직이랑 똑같은데 도댜체 뭐가 틀렸던 거냐!
 => 캐시가 다 찼는가에 대한 조건문이 틀림 len(cache) <= cacheSize 면 0일때 캐시에 넣어버리는 불상사 발생
"""
def solution(cacheSize, cities):
    answer = 0

    cache = {}
    time = 0
    
    if(cacheSize==0):
        return 5*len(cities)

    for city in cities: 
        time += 1
        city = city.upper()
        # cache에 city가 있는가?
        if city in cache:
            # hit
            answer += 1
        else:
            # miss
            answer += 5
            
            # cache에 자리가 있는가?
            if len(cache) == cacheSize:
                # 참조횟수 제일 작은 놈으로  -> 찾기!!
                deleted = min(cache, key=cache.get)
                del cache[deleted]

        cache[city] = time

    return answer

"""
# 좀 더 깔끔한 버전
def solution(cacheSize, cities):
    answer = 0

    cache = {}
    if cacheSize ==0:
        return len(cities)*5
    time = 0
    for city in cities: 
        time += 1
        
        city = city.upper()
        
        if city not in cache:
            answer += 5
            
            # 캐시가 다 찼을 때 -> 삭제 해준다.
            if len(cache)==cacheSize:
                deleted = min(cache, key=cache.get)
                del cache[deleted]
        else:
            answer += 1
        
        cache[city] = time
    #print(cache, answer)
    return answer
"""