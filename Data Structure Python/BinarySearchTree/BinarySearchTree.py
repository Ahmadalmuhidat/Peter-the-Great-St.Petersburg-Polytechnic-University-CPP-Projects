class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:

    # privet methods

    # BST constructor
    def __init__(self):
        self.__head = None  # Tree head pointer
        self.__count = 0   # Number of nodes in the tree

    # add item to tree
    def __addItemPrivet(self, val, node):
        newNode = Node(val)
        if self.__count == 0:
            self.__head = newNode
            self.__count += 1

        else:

            if val < node.data:  # add to left
                if node.left == None:
                    node.left = newNode
                    self.__count += 1
                else:
                    self.__addItemPrivet(val, node.left)

            elif val > node.data:  # add to right
                if node.right == None:
                    node.right = newNode
                    self.__count += 1
                else:
                    self.__addItemPrivet(val, node.right)

            else:
                print(str(val), "has been already inserted to the tree")

    def __searchPrivet(self, val, node):

        if node.data == val:
            print(val, "found")
            return val
        else:
            if node.data > val:
                return self.__searchPrivet(val, node.left)

            if node.data < val:
                return self.__searchPrivet(val, node.right)

    def __DisplayPrivet(self, node):

        if self.isEmpty() == True:
            print("Tree is empty")

        else:
            print(node.data)

            if node.right != None:
                self.__DisplayPrivet(node.right)

            if node.left != None:
                self.__DisplayPrivet(node.left)

# public methods

    # Display the tree
    def Display(self):
        self.__DisplayPrivet(self.__head)

    # Seatch for value in the tree
    def search(self, val):
        self.__searchPrivet(val, self.__head)

    # return how many node we have in the tree
    def count(self):
        return self.__count

    # check if the tree is empty or not
    def isEmpty(self):
        if self.__count == 0:
            return True
        else:
            return False

    # Delete node from the tree
    def deleteItem(self):
        print()

    # Add item to the tree
    def addItem(self, val):
        self.__addItemPrivet(val, self.__head)
