class Node:
    def __init__(self,
                 data):

        self.previous = None
        self.data = data
        self.next = None


class DoubleLinkedList:
    def __init__(self):
        self.head = None

    def findNode(self,
                 data):

        temp = self.head
        while (temp.data != data):
            temp = temp.next
        if (temp.data == data):
            return True
        else:
            return False

    def insert(self,
               data):

        newNode = Node(data)
        if self.head == None:
            self.head = newNode
        elif self.head != None:
            temp = self.head
            while (temp.next != None):
                temp = temp.next
            temp.next = newNode
            temp.next.previous = temp

    def nodeInfo(self,
                 data):

        temp = self.head
        while (temp.data != data):
            temp = temp.next
        if temp == None:
            print("[-] not found")
        else:
            def checkNone(x): return x.data if (x == None) == False else "None"
            print("data: {}".format(temp.data))
            print("next: {}".format(checkNone(temp.next)))
            print("previous: {}".format(checkNone(temp.previous)))

    def delete(self,
               data):

        if (self.head.data == data):
            self.head = self.head.next
            pass
        else:
            temp = self.head
            prevNode = None
            nextNode = None
            while (temp.data != data):
                temp = temp.next
            if temp.next == None:
                temp.previous.next = None
                pass
            else:
                prevNode = temp.previous
                nextNode = temp.next
                temp.next = None
                temp.previous = None
                temp = None
                prevNode.next = nextNode
                nextNode.previous = prevNode

    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=' ')
            temp = temp.next
        print()

    def update(self,
               oldData,
               newData):

        temp = self.head
        while (temp.data != oldData):
            temp = temp.next
        temp.data = newData
