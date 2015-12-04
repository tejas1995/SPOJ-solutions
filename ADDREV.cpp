#include <iostream>
using namespace std;
typedef unsigned long int ulong;

ulong reverse(ulong num)
{
	ulong rev = 0;
	while(num > 0)
	{
		rev *= 10;
		rev += num % 10;
		num /= 10;
	}
	return rev;
}

int main()
{
	int N;
	cin >> N;

	while(N--)
	{
		ulong num1, num2;
		cin >> num1 >> num2;

		cout << reverse(reverse(num1) + reverse(num2)) << endl;
	}

	return 0;
}