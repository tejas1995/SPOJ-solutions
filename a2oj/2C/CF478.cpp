//http://codeforces.com/problemset/problem/478/C

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int a[3];
	long long int sum = 0, max = -1, maxIndex = -1;
	for(long long int i = 0; i < 3; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a+3);
	long long int maxTables = sum/3;
	if(maxTables > a[0]+a[1])
		cout << a[0]+a[1] << endl;
	else
		cout << maxTables << endl;
	return 0;
}