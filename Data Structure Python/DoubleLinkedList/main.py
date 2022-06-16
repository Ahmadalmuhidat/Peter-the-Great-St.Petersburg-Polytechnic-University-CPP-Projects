from DoubleLinkedList import DoubleLinkedList
import sys
sys.path.insert(0, "DoubleLinkedList")


if __name__ == '__main__':

    test = DoubleLinkedList()
    test.insert(100)
    test.insert(22)
    test.insert(45)
    test.insert(87)
    test.printList()

    test.nodeInfo(100)

    print(test.findNode(22))

    test.update(100, 30)
    test.printList()

    test.delete(22)
    test.printList()
