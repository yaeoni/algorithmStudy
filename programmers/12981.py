# dict 이용
def solution(n, words):
    answer = []
    
    dic = {}
    if len(words[0]) < 2: 
        return [1,1] 
    dic[words[0]] = 1
    
    for i in range(1, len(words)):
        
        if len(words[i]) < 2 or (words[i] in dic) or words[i-1][-1] != words[i][0]:
            return [i%n+1, int(i/n+1)]
        else:
            dic[words[i]] = 1
    return [0,0]