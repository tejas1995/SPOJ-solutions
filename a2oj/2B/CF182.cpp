//http://codeforces.com/problemset/problem/182/B

#include <iostream>
using namespace std;

typedef unsigned long long int uLong;

int main()
{
	uLong d, n;
	cin >> d >> n;
	uLong numChanges = 0, monthDays;
	for(int i = 1; i <= n; i++)
	{
		cin >> monthDays;
		if(i != n)
			numChanges += d - monthDays;
	}
	cout << numChanges << endl;
	return 0;
}