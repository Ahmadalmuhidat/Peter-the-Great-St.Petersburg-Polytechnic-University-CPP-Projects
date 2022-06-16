from Queue import Queue
import sys
sys.path.append("Queue")

if __name__ == '__main__':
    queue = Queue(10)

    queue.Enqueue(1)
    queue.Enqueue(2)
    queue.Enqueue(3)
    queue.Enqueue(4)
    queue.Enqueue(5)
    queue.printList()

    queue.Dequeue()
    queue.printList()

    print("List count:", queue.count())
