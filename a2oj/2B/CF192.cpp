//http://codeforces.com/problemset/problem/192/B

#include <iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int n;
	cin >> n;
	int prev=-1, k, minDays=-1;
	for(int i=0; i < n; i++){
		cin >> k;
		if(i == 0)
			minDays = k;
		else if(max(prev, k) < minDays)
			minDays = max(prev, k);
		else if(i == n-1 && k < minDays)
			minDays = k;
		prev = k;
	}
	cout << minDays << endl;
	return 0;
}