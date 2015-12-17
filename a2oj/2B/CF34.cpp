//http://codeforces.com/problemset/problem/34/B

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, total=0;
	cin >> n >> m;
	int *a = new int [n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	for(int i = 0; i < m; i++)
		if(a[i] < 0)
			total -= a[i];
		else
			break;
	cout << total << endl;
	return 0;
}