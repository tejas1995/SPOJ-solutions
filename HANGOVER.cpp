#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	float c, n;

	while(true)
	{
		cin >> c;
		if(c == 0.00)
			break;

		int k = 1;
		float total_length = 0.00;
		do
		{
			k++;
			total_length += 1.0/k;
		}while(total_length <= c);
		cout << k-1 << " card(s)\n";
	}

	return 0;
}