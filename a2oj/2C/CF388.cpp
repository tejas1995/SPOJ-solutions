//http://codeforces.com/problemset/problem/388/A

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, numZero=0;
	cin >> n;
	int *w = new int [n];
	for(int i = 0; i < n; i++){
		cin >> w[i];
		if(w[i] == 0)
			numZero++;
	}
	sort(w, w+n);
	for(int k = 1; k <= n; k++)
	{
		for(int i = 0; i < n; i++){
			if(w[i] < i/k){
				break;
			}
			else if(i == n-1){
				cout << k << endl;
				return 0;
			}
		}
	}
	return 0;
}