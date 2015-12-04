#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef unsigned long int uLong;

void swap(int arr[], int m, int n)
{
	int temp = arr[m];
	arr[m] = arr[n];
	arr[n] = temp;
}

int partitionSegment(int arr[], int start, int end, int p)
{
	swap(arr, start, p);

	int i = start+1, j;

	for(j = start+1; j <= end; j++)
	{
		if(arr[j] < arr[start])
		{
			swap(arr, i, j);
			i++;
		}
	}

	swap(arr, i-1, start);
	return i-1;
}

void quickSort(int arr[], int start, int end)
{
	if(start == end)
	{
		return;
	}
	else
	{
		int partition = rand() % (end-start+1) + start;
		int partitionIndex = partitionSegment(arr, start, end, partition);

		if(start != partitionIndex)
			quickSort(arr, start, partitionIndex-1);
		if(end != partitionIndex)
			quickSort(arr, partitionIndex+1, end);
	}
}

int main()
{
	int t, N;
	cin >> t;

	int male[1000];
	int female[1000];

	srand(time(NULL));

	while(t--)
	{
		cin >> N;

		for(int i = 0; i < N; i++)
			cin >> male[i];
		for(int i = 0; i < N; i++)
			cin >> female[i];

		quickSort(male, 0, N-1);
		quickSort(female, 0, N-1);

		uLong sumHotnessBond = 0;

		for(int i = 0; i < N; i++)
			sumHotnessBond += male[i] * female[i];

		cout << sumHotnessBond << endl;
	}
}