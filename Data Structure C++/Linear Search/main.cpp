#include <iostream>
using namespace std;

void LinearSearch(int arr[], int size, int val)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == val)
		{
			std::cout << val << " found in position " << i + 1 << endl;
			temp = 1;
		}
	}
	if (temp == 0)
	{
		std::cout << val << " not found" << endl;
	}
}

int main()
{
	int arr[] = {1, 3, 5, 6, 9, 4, 30, 13, 18, 22};
	int size = sizeof(arr) / sizeof(*arr);
	int target;
	std::cout << "target: ";
	cin >> target;
	LinearSearch(arr, size, target);

	return 0;
}