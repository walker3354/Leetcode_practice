class LinkNode:
    def __init__(self, value=0):
        self.value = value
        self.next = None


class LinkedList:

    def __init__(self):
        self.node_counter = 0
        self.head_node = None
        self.tail_node = None

    def get(self, index: int) -> int:
        if index < 0 or index >= self.node_counter:
            return -1
        temp = self.head_node
        for i in range(index):
            temp = temp.next
        return temp.value

    def insertHead(self, val: int) -> None:
        temp = LinkNode(val)
        if self.head_node == None:
            self.head_node = self.tail_node = temp
            temp.next = None
        else:
            temp.next = self.head_node
            self.head_node = temp
        self.node_counter += 1

    def insertTail(self, val: int) -> None:
        temp = LinkNode(val)
        temp.next = None
        if self.tail_node == None:
            self.head_node = self.tail_node = temp
        else:
            self.tail_node.next = temp
            self.tail_node = temp
        self.node_counter += 1

    def remove(self, index: int) -> bool:
        if index < 0 or index >= self.node_counter:
            return False
        else:
            temp = self.head_node
            if index == 0:
                self.head_node = temp.next
            else:
                for i in range(index - 1):
                    temp = temp.next
                delete_node = temp.next
                if delete_node == self.tail_node:
                    self.tail_node = temp
                    self.tail_node.next = None
                else:
                    temp.next = delete_node.next
            self.node_counter -= 1
            return True

    def getValues(self) -> list[int]:
        result = []
        temp = self.head_node
        while temp != None:
            result.append(temp.value)
            temp = temp.next
        return result
