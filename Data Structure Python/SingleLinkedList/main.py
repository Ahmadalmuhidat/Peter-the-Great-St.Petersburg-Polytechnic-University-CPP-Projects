from SingleLinkedList import SingleLinkedList
import sys

sys.path.append("SingleLinkedList")

if __name__ == '__main__':

    SingleList = SingleLinkedList()
    
    SingleList.insert(1)
    SingleList.insert(2)
    SingleList.insert(3)
    SingleList.insert(4)
    SingleList.insert(5)
    SingleList.PrintList()
    
    SingleList.findeNode(4)
    SingleList.findeNode(7)
    
    SingleList.updateNode(3, 10)
    SingleList.PrintList()
    
    SingleList.deleteNode(5)
    SingleList.PrintList()
