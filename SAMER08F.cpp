#include <iostream>
using namespace std;

int main()
{
	int N;

	do
	{
		cin >> N;

		if(N != 0)
			cout << N*(N+1)*(2*N+1)/6 << endl;
		
	} while(N != 0);
}