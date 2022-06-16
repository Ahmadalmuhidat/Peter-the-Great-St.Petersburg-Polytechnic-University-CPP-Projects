from BinarySearchTree import BST
import sys
sys.path.insert(0, "BinarySearchTree")

if __name__ == '__main__':
    tree = BST()

    tree.addItem(4)
    tree.addItem(2)
    tree.addItem(5)
    tree.addItem(1)

    tree.Display()

    print("val count:", tree.count())

    tree.search(5)

  #         4
  #   2           5
  # 1  none   none  none
