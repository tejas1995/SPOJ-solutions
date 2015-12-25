//http://codeforces.com/problemset/problem/205/B

#include <iostream>
using namespace std;

int main()
{
	long long int n, k, prev=0, changes=0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> k;
		if(i != 0 && k < prev)
			changes += prev-k;
		prev = k;
	}
	cout << changes << endl;
	return 0;
}