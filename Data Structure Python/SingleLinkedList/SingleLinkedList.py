#!/usr/bin/env python3

class Node:
    def __init__(self, data):
        self.data = data # node value
        self.next = None # point to the next node


class SingleLinkedList:

    # constructor
    def __init__(self):
        self.head = None

    # find node and return it
    def findeNode(self, target) -> Node:
        temp = self.head
        while (temp.next != None):
            if temp.data == target:
                break
            elif temp.data != target:
                temp = temp.next

        if (temp.data == target):
            return temp
        else:
            pass

    # add node to the list
    def insert(self, data):
        # create new node
        NewNode = Node(data)

        # check if node is empty
        if self.head == None:
            self.head = NewNode

        elif self.head != None:
            temp = self.head

            while (temp.next != None):
                temp = temp.next
            temp.next = NewNode

    # update node value
    def updateNode(self, oldData, newData):
        temp = self.head
        while (temp.data != oldData):
            temp = temp.next
        temp.data = newData

    # display list
    def PrintList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=' ')
            temp = temp.next
        print()

    # delete node from the list
    def deleteNode(self, target):

        # if the head is the wanted value
        if self.head.data == target:
            self.head = self.head.next
        else:
            prevNode = self.head
            temp = prevNode.next
            while (temp != None):

                if temp.data == target:
                    prevNode.next = temp.next
                    temp = None
                    break

                if temp == None:
                    prevNode.next = temp.next

                else:
                    temp = temp.next
                    prevNode = prevNode.next
