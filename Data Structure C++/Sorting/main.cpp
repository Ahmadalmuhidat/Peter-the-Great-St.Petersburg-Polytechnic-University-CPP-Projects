#include <iostream>
#include <vector>
#include "SortByInsertion.h"
#include "MergeSort.h"
#include "SortByCount.h"
using namespace std;

void Sort_By_Insertion();
void Sort_By_Count();
void Merge_Sort();

int main()
{
   setlocale(LC_ALL, "Russian");

   cout << "Test sort by insertion\n";
   Sort_By_Insertion();

   cout << "=============================\n";
   cout << "Test sort by count\n";
   Sort_By_Count();

   cout << "=============================\n";
   cout << "Test merge sort\n";
   Merge_Sort();

   return 0;
}

void Sort_By_Insertion()
{
   int a[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
   int n = sizeof(a) / sizeof(a[0]), i;

   cout << "Before Sorting the array: \n";
   for (i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
   cout << "\n";

   insertionSort(a, n);

   cout << "Sorted array: \n";
   for (i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
   cout << "\n";
}

void Sort_By_Count()
{
   vector<int> arr{1, 4, 1, 2, 7, 5, 2};
   CountSort(arr);
}

void Merge_Sort()
{
   int arr[] = {12, 11, 13, 5, 6, 7};
   int arr_size = sizeof(arr) / sizeof(arr[0]); // get the array length
   cout << "Given array is \n";
   printArray(arr, arr_size);

   MergeSort(arr, 0, arr_size - 1);

   cout << "\nSorted array is \n";
   printArray(arr, arr_size);
}