"""
- 기억하는 멜로디 끝->처음일 수도
- 중간에 끊었따면 그 곡이 아닐 수도

- 조건 일치 여러개면 재생 시간 제일 긴 놈 / 같으면 먼저 입력된 놈 / 없으면 "(NONE)" 반환

- 음악 시작 시각 / 끝난 시각 / 음악 제목 / 악보 정보

해야할 일 ) 
1. 음악 시작-끝 동안 재생된 멜로디 문자열 만들기
    - 시작-끝 시간 계산하기 (시간이니까 기준 60인데...)
2. 해당 문자열에 m이 들어가있는지 확인 
3. 둘 다 만족한다면 candidate배열에 넣어놓고 반환기준 만족하는 놈으로 리턴하기

추가적인 고려점) # 이 놈에서 말썽이다!
=> #이 들어가는 놈들은 한문자로 "치환"을 시켜버리자!호우호우 str.replace(A,B)
=> 해당 문자열이 들어가는지 판별 str.find() // -1 이면 없는거

~에러~
- 런타임 에러랑 이것저것 다 실패뜸
- 치환 이후에는 어휴.. 및ㄴ친 None인데 NONE을 반환했음 ㅜ
"""
    
def solution(m, musicinfos):
    answer = []
    
    def replaceFunc(s):
        s = s.replace('A#','a')
        s = s.replace('F#','f')
        s = s.replace('C#','c')
        s = s.replace('D#','d')
        s = s.replace('G#','g')
        return s
    
    m = replaceFunc(m)
    
    for musicinfo in musicinfos:  
        start, end, title, keys = musicinfo.split(",")
    
        keys = replaceFunc(keys)
        
        # 시간 계산하기
        min=0
        
        start_token = list(map(int,start.split(":")))
        end_token = list(map(int,end.split(":")))
        
        if(end_token[1] < start_token[1]):
            # 13: 50 / 13 : 65 
            end_token[0] -= 1
            end_token[1] += 60
        
        
        min += end_token[1]-start_token[1]
        if end_token[0] > start_token[0]:
            min += (end_token[0]-start_token[0])*60 
        
        # 재생된 시간만큼의 재생된 문자열 생성     
        played = ""
        for i in range(min):
            played += keys[i%len(keys)]
            
        if(played.find(m)) != -1:
            answer.append([title, min])
        # 안에 해당 문자열이 들어가있는가 판별
    
    if not answer:
        return "(None)"
    # time기준으로 긴 것 부터니까 reverse=True 고 람다로 조건을 넣어주는거임
    answer.sort(reverse=True, key = lambda x: x[1])
    return answer[0][0]