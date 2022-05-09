// DequeSTL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], int n, int k) 
{
	deque<int> deq;
	int max = 0;
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		if (i < k)
		{
			deq.push_back(arr[i]);

			if (max <= arr[i])
			{
				max = arr[i];
				index = i;
			}

			if (i == k - 1)
				cout << max << ' ';
		}
		else
		{
			if (index == 0)
			{
				index = -1;
			}

			deq.pop_front();

			index--;

			if (max <= arr[i])
			{
				max = arr[i];
				index = k - 1;
			}

			deq.push_back(arr[i]);

			if (index < 0)
			{
				max = 0;

				for (int i = 0; i < deq.size(); i++)
				{
					if (deq[i] >= max)
					{
						index = i;
						max = deq[i];
					}
				}
			}

			cout << max << ' ';
		}
	}

	cout << endl;
}

int main()
{
	int arr[]{ 3, 4, 6, 3, 4 };

	printKMax(arr, 5, 2);

	int arr2[]{ 3, 4, 5, 8, 1, 4, 10 };

	printKMax(arr2, 7, 4);

	return EXIT_SUCCESS;
}
