//http://codeforces.com/problemset/problem/466/C

#include <iostream>
using namespace std;
typedef long long int uLong;

int main()
{
	uLong n;
	cin >> n;
	uLong *a = new uLong [n];
	uLong sum = 0, oneThird = 0, twoThird = 0;
	for(uLong i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	if(sum % 3 != 0){
		cout << "0\n"; return 0;
	}

	uLong sumSoFar = 0, numPairs = 0;
	for(uLong i = 0; i < n; i++)
	{
		sumSoFar += a[i];
		if(sumSoFar == 2*sum/3 && i < n-1){
			numPairs += oneThird;
		}
		if(sumSoFar == sum/3)
			oneThird++;
	}

	cout << numPairs << endl;
	return 0;
}