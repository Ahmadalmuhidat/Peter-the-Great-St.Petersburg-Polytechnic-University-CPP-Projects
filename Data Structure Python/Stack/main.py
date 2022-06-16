from Stack import Stack
import sys

sys.path.insert(0, "Stack")

if __name__ == '__main__':
    stack = Stack(10)
    stack.push(1)
    stack.push(2)
    stack.printList()
    stack.pop()
    stack.printList()
    stack.update(1, 4)
    stack.printList()
    print(stack.count())
    stack.peek(0)
