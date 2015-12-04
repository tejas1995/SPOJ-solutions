#include <iostream>
using namespace std;

typedef unsigned long int uLong;

int main()
{
	uLong t;
	cin >> t;

	while(t--)
	{
		int x, y;
		cin >> x >> y;
		
		if(x == y)
		{
			if(x % 2 == 0)
				cout << 2*x << endl;
			else
				cout << 1 + 2*(x-1) << endl;
		}
		else
		if(x == y+2)
		{
			if(x % 2 == 0)
				cout << 2*(y+1) << endl;
			else
				cout << 2*y+1 << endl;
		}
		else
			cout << "No Number\n";
	}
}