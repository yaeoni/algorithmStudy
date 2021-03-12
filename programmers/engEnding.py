"""
- 나온 단어들 모음 ~ Trie
- 사람이 몇 번째 차례에 탈락하는가 - n만큼 배열 세워놓고 카운트
- 단어 idx % n 으로 = 0 => 1번째 사람..

탈락 기준 
- 말한 것 또 말하기 => 트라이로 해결
- 끝말잇기가 아닌 것 => 포문으로 내에서 해결
"""
# Trie 구현 -> 또 까먹었당... 트라이 구현하는거 제발 머리에 박아.. 도대체 몇번을 확인함 후개짜중
class Node:
    def __init__(self, key): 
        self.key = key
        self.child= {}
        self.flag = False

class Trie:
    def __init__(self):
        self.head = Node(None)
        
    def insertAndCheck(self, strings):
        cur = self.head
        
        for s in strings:
            if s not in cur.child:
                cur.child[s] = Node(None)
            cur = cur.child[s]
        
        # 이미 단어가 존재 했다면 끝나는 것, 대문자 넣어서 더미데이터화
        if(cur.flag==True):
            return False
        
        # 단어가 존재하지 않으면 끝점 표시를 하고 맨 끝 글자 함께 리턴
        cur.flag = True
        
        return True
        
def solution(n, words):
    trie = Trie()
    
    # 자신이 몇 번째 차례인지 체크해야하는 용도의 배열
    count = [0]*n
    
    compared = None
    for idx, word in enumerate(words):
        flag = trie.insertAndCheck(word)
        count[idx%n] += 1
        
        if(idx == 0):
            # 첫번째 글자는 초기화만 
            compared = word[len(word)-1]
        else:
            if(compared != word[0]):
                # compared(끝점)과 첫번째 글자 비교
                flag =False
            
            else:
                # 끝점과 첫점 같자면 끝점 업데이트 (해당 글자의 맨 끝 글자로)
                compared = word[len(word)-1]
                
        if(flag == False):
            return [(idx%n)+1, count[idx%n]]
            
    return [0,0]