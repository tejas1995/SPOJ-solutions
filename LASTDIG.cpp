#include <iostream>
using namespace std;

int main()
{
	int t, a;
	unsigned long int b;

	b=-1;
	cout << b << endl;
	cin >> t;

	while(t--)
	{
		cin >> a >> b;

		int baseLast = a % 10;
		int nextLast = (baseLast * baseLast) % 10;
		int numDistinctLast = 1;

		while(nextLast != baseLast)
		{
			numDistinctLast++;
			nextLast = (nextLast * baseLast) % 10;
		}

		int *lastDigit = new int [numDistinctLast];
		nextLast = baseLast;

		for(int i = 0; i < numDistinctLast; i++)
		{
			lastDigit[i] = nextLast;
			nextLast = (nextLast * baseLast) % 10;
			cout << i << " : " << lastDigit[i] << "\t";
		}
		cout << endl;
		
		if(b % numDistinctLast == 0)
			cout << lastDigit[b % numDistinctLast + numDistinctLast - 1] << endl;
		else
			cout << lastDigit[b % numDistinctLast - 1] << endl;
	}

	return 0;
}