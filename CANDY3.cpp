#include <iostream>
using namespace std;

typedef unsigned long long int uLong;

int main()
{
	uLong t;
	cin >> t;

	while(t--)
	{
		uLong n, k;
		cin >> n;
		uLong sum = 0;

		for(uLong i = 0; i < n; i++)
		{
			cin >> k;
			sum = (sum + k) % n; 
		}

		if(sum == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}