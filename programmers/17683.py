# c++ 이랑 똑같은 로직이라고 생각했는데, 런타임 에러가 잔뜩나네,,
# # 때문에 index 처리할 것이 잔뜩이었다. 낼은 치환하는 방법을 써봐야지
def solution(m, musicinfos):
    answer = ''
    
    cand = []
    for musicinfo in musicinfos:
        info = musicinfo.split(",")
        
        start = info[0].split(":")
        end = info[1].split(":")
        
        play = (int(end[0])*60+int(end[1])) - (int(start[0])*60+int(start[1]))
        
        # 악보 만들기
        sheet = info[3]
        playSheet = ""
        
        idx = 0
        for _ in range(play):
            if(idx == len(sheet)): idx = 0
            
            playSheet += sheet[idx]
            idx += 1
            
            if(idx < len(sheet) and sheet[idx] == '#'):
                playSheet += sheet[idx]
                idx += 1
        
        # 악보내에 있는지 확인 
        idx = playSheet.find(m)

        while(idx != -1):
            if(idx+len(m) == len(playSheet)):
                cand.append((play, info[2]))
                break
            if( idx+len(m) < len(playSheet) and playSheet[idx+len(m)] != '#'):
                cand.append((play, info[2]))
                break
            idx = playSheet.find(m, idx+len(m))
    
    if(len(cand) == 0): return "(None)"
    
    cand = sorted(cand, key= lambda x : x[0], reverse=True)
    
    return cand[0][1]