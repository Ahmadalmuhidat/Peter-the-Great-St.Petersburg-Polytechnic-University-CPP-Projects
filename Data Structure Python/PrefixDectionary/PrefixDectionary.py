class Node:
    def __init__(self):
        self.prefix_count = 0
        self.isWord = False
        self.children = [None] * 26


class Dictionary:

    # constructor
    def __init__(self):
        self.head = Node() # head pointer
        self.head.isWord = False # check if the node is word
        self.head.prefix_count = 0

    # convert char to int (index)
    def charToindex(self, char):
        return ord(char) - ord('a')

    # add value to the dictionary
    def insert(self, word):
        temp = self.head
        temp.prefix_count += 1

        for i in range(len(word)):

            index = self.charToindex(word[i])

            if temp.children[index] == None:
                temp.children[index] = Node()

            temp.children[index].prefix_count += 1
            temp = temp.children[index]

        temp.isWord = True

    def search(self, word):
        current = self.head

        for i in range(len(word)):
            index = self.charToindex(word[i])

            if current.children[index] == None:
                return False
            current = current.children[index]

        return current.isWord

    def words_with_prefix(self, word):
        current = self.head

        for i in range(len(word)):
            index = self.charToindex(word[i])

            if current.children[index] == None:
                return 0
            else:
                current = current.children[index]

        return current.prefix_count

    def isEmpty(self, node):
        char_size = 128

        for i in range(0, char_size):
            if node.children[i]:
                return False
            else:
                return True

    def remove(self, node, key, depth=0):
        if (node == None):
            return None

        if depth == len(key):
            if node.isWord:
                node.isWord = False

            if self.isEmpty(node):
                del node
                node = None

            return node
        index = self.charToindex(key[depth])
        node.children[index] = self.remove(
            node.children[index], key, depth + 1)

        if (self.isEmpty(node) and node.isWord == False):
            del node
            node = None

        return node
