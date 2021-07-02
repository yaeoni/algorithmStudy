# 로컬에서 구현 시 필요
class ListNode:
    def __init__(self, item):
        self.val = item
        self.next = None

class MyCircularDeque:
    def __init__(self, k:int):
        self.head, self.tail = ListNode(None), ListNode(None) # None value를 넣어서 dummy 역할
        self.k, self.len = k, 0
        self.head.right, self.head.left = self.tail, self.head


    def _add(self, node: ListNode, new: ListNode):
        n = node.right # 담아두고
        node.right = new
        new.left, new.right = node, n
        n.left = new

    def _del(self, node: ListNode):
        n = node.right.right 
        node.right = n
        n.left = node

    def insertFront(self, value: int) -> bool:
        if self.len == self.k: # if full
            return False
        self.len += 1
        self._add(self.head, ListNode(value))
        return True
    
    def insertLast(self, value: int) -> bool :
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.tail.left, ListNode(value))
        
    def deleteFront(self) -> bool:
        if self.len == 0:
            return False
    
        self.len -= 1
        self._del(self.head)
        return True
    
    def deleteBack(self) -> bool:
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.tail.left.left)
        return True
    
    def getFront(self) -> int:
        return self.head.right.val if self.len else -1
    
    def getRear(self) -> int:
        return self.tail.left.val if self.len else -1

    def isEmpty(self) -> bool:
        return self.len == 0
    
    def isFull(self) -> bool:
        return self.len == k

if __name__ == '__main__':
    cd = MyCircularDeque(5)
    cd.insertFront(1)
    cd.insertFront(2)

    print(cd.getFront())
    print(cd.getRear())