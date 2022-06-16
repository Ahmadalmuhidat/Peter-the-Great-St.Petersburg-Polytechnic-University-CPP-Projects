#include <iostream>
#include <vector>
#include <algorithm>
#include "SortByCount.h"
using namespace std;

void CountSort(vector<int> a)
{
	struct Number
	{
		int num;
		int count;
		Number(int n)
		{
			this->num = n;
			this->count = 0;
		}
		void set_count(int c)
		{
			this->count = c;
		}
	};

	vector<Number> list;

	for (int i = 0; i < a.size(); i++)
	{
		Number index(i);
		list.push_back(index);
	}

	for (auto number : a)
	{
		int number_count = count(a.begin(), a.end(), number);

		for (auto &obj : list)
		{
			if (obj.num == number)
			{
				obj.set_count(number_count);
			}
			else
			{
				continue;
			}
		}
	}

	for (Number obj : list)
	{
		cout << obj.num << ": " << obj.count << endl;
	}
}