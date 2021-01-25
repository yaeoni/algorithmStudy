from sys import stdin

class Node:
    def __init__(self, key, data=None):
        # 저장될 기준 알파벳
        self.key = key
        # 현재 문자가 제일 끝인지 판별해주는 flag
        # 몇 개가 저장되는지 체크 -> 문제를 풀어야하니깐.
        self.count = 0
        # 끝났는데 단어가 더 이어지는 경우를 대비한 단어 자체
        self.data = data
        self.children = {}

class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        cur = self.head

        for char in string:
            if char not in cur.children:
                cur.count += 1
                cur.children[char] = Node(char)
            cur = cur.children[char]
            
        # 끝 점이다.
        cur.data = string

    def search(self, string):
        cur = self.head.children[string[0]]
        ret = 1

        for char in string[1:]:
            # 자식이 2개 이상 인 것들 / 해당 위치가 어떤 단어의 끝인 경우 -> 버튼을 눌러줘야 안다.
            if (cur.count != 1 and cur.count != 0) or (cur.data !=None and cur.data != string):
                ret += 1

            cur = cur.children[char]

        return ret

try:
    while(True):
        n = int(stdin.readline())
        
        t = Trie()
        words = []
        ret = 0

        for _ in range(n):
            temp = stdin.readline().strip('\n')
            words.append(temp)
            t.insert(temp)
        
        for string in words:
            ret += t.search(string)
   
        print("%.2f" % (ret/len(words)))
except:
    exit(0)
"""
a = Trie()

a.insert("hello") #3
a.insert("hell") #2
a.insert("heaven") #2
a.insert("goodbye") #1
print("final", a.search("hello"))
print("final", a.search("hell"))
print("final", a.search("heaven"))
print("final", a.search("goodbye"))

a.insert("hi")
a.insert("he")
a.insert("h")
print("final", a.search("hi"))
print("final", a.search("he"))
print("final", a.search("h"))
"""