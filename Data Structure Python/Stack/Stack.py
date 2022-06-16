class Stack:
    def __init__(self, size):
        self.top = -1
        self.size = size
        self.array = [None] * size

    def isFull(self):
        if self.top == -1:
            return True
        else:
            return False

    def IsEmpty(self):
        if self.top == self.size:
            return True
        else:
            return False

    def push(self, data):
        if self.IsFull() == True:
            print("[-] array is full")
        else:
            self.top += 1
            self.array[self.top] = data

    def pop(self):
        if self.IsEmpty():
            print("[-] nothing to pop")
        else:
            self.top -= 1
            del self.array[self.top]

    def count(self):
        result = 0
        for val in self.array:
            if val == 0:
                continue
            else:
                result += 1
        return result

    def peek(self, pos):
        print(self.array[pos])

    def update(self, pos, newVal):
        self.array[pos] = newVal

    def printList(self):
        for val in self.array:
            if val == None:
                continue
            else:
                print(val, end=' ')
        print()
