class Node:
    def __init__(self, key):
        # 저장될 기준 알파벳
        self.key = key
        # 현재 문자가 제일 끝인지 판별해주는 flag
        self.flag = False
        # 딕셔너리를 이용해 해당 문자를 삽입하거나, 있는지 확인하는 용도
        self.children = {}

class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        cur = self.head

        for char in string:
            if char not in cur.children:
                cur.children[char] = Node(char)
            cur = cur.children[char]

        # 끝 점이다.
        print("last char: ", cur.key)
        cur.flag = True

    def search(self, string):

        cur = self.head

        for char in string:
            if char not in cur.children:
                return False
            cur = cur.children[char]

        if cur.flag == True:
            return True

        return False
a = Trie()
a.insert("abc")
print(a.search("abc"))
print(a.search("ab"))