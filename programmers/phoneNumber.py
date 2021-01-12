# 어떤 번호가 다른 번호의 접두사
# 길이가 짧은 것 부터 { "123" : [a, b, c] } 맞는게 하나라도 
# 그래서 전에는 trie를 썼던 것 같네요, 근데 트라이 말고는 생각이 안나는다. -> 파이썬으로 트라이 구현

# 길이 기준 sort 필요 => 01010, 010 일 때 010을 먼저 넣어야 01010의 접두어 여부 판단 가능
class Node:
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}
        

class Trie:
    def __init__(self):
        self.head = Node(None)
    
    def search(self, string):
        cur = self.head
        
        for char in string:
            if char not in cur.children:
                cur.children[char] = Node(None)
            cur = cur.children[char]
            
            if cur.data is not None:
                return False
        cur.data = string
        return True
                
def solution(phone_book):
    answer = True
    phone_book.sort()

    trie = Trie()
    
    for num in phone_book:
        if(trie.search(num)==False):
            return False
    return True