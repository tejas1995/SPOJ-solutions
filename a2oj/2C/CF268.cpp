//http://codeforces.com/problemset/problem/268/C

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int min = (m < n ? m : n);
	cout << min+1 << endl;
	for(int i = 0; i <= min; i++)
		cout << i << " " << min-i << endl;
	return 0;
}