#include <iostream>
using namespace std;

typedef unsigned long long int uLong;

int main()
{
	uLong T, N;
	cin >> T;

	for(uLong i = 0; i < T; i++)
	{
		cin >> N;
		uLong totalZeroes = 0;

		while(N >= 5)
		{
			totalZeroes += N/5;
			N /= 5;
		}
		cout << totalZeroes << endl;
	}

	return 0;
}