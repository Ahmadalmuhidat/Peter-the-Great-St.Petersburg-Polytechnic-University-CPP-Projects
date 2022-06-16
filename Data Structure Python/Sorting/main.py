import SortByMerge
import SortByCount
import SortByInsertion
import sys
sys.path.insert(0, "Sorting")


if __name__ == '__main__':

    print("\nSort By Merge")
    arr = [12, 11, 13, 5, 6, 7]
    print("Given array is", end="\n")
    SortByMerge.printList(arr)
    SortByMerge.mergeSort(arr)
    print("Sorted array is: ", end="\n")
    SortByMerge.printList(arr)

    print("\nSort By Count")
    arr = "geeksforgeeks"
    ans = SortByCount.countSort(arr)
    print("Sorted character array is % s" % ("".join(ans)))

    print("\nSort By Insertion")
    arr = [12, 11, 13, 5, 6]
    SortByInsertion.insertionSort(arr)
    for i in range(len(arr)):
        print(arr[i], end=' ')
        
