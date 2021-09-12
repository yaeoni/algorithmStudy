# python은 쉽게 list의 요소를 찾을 수 있으니까 ! break를 안걸어도 된다 ㅎ
def solution(cacheSize, cities):
    answer = 0
    
    cache = []
    
    for city in cities:
        city = city.lower()
        
        flag = False
        
        if city in cache:
            answer += 1
            cache.remove(city)
            cache.append(city)
            flag = True
            
        if flag != True:
            answer += 5
            if(cacheSize != 0 and len(cache) >= cacheSize):
                cache.pop(0)
            if(len(cache) < cacheSize):
                cache.append(city)
            
    return answer