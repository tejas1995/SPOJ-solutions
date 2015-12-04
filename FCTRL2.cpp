#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

int main()
{

	using namespace boost::multiprecision;

	int1024_t factorial;
	int t, N;

	cin >> t;

	while(t--)
	{
		cin >> N; 

		factorial = 1;
		for(int i = 2; i <= N; i++)
			factorial *= i;
		cout << factorial << endl;
	}



}