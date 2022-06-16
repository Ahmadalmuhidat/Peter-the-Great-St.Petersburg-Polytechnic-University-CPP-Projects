class Queue:
    def __init__(self, size):
        self.front = -1
        self.tail = -1
        self.size = size
        self.array = [None] * size

    def isFull(self):
        if (self.tail == self.size):
            return True
        else:
            return False

    def isEmpty(self):
        if (self.tail == -1) and (self.front == -1):
            return True
        else:
            return False

    def Enqueue(self, data):
        if self.isFull():
            print("[-] array is full")
        elif self.isEmpty():
            self.front = 0
            self.tail = 0
            self.array[self.tail] = data
        else:
            self.tail += 1
            self.array[self.tail] = data

    def Dequeue(self):
        if self.isEmpty():
            print("[-] is empty")
        elif self.front == self.tail:
            del self.array[self.tail]
        else:
            del self.array[self.tail]
            self.tail -= 1

    def printList(self):
        for x in self.array:
            if x == None:
                pass
            else:
                print(x, end=' ')
        print()

    def count(self):
        return len(self.array)
