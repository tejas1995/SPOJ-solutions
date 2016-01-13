//http://codeforces.com/problemset/problem/69/B

#include <iostream>
using namespace std;

int main()
{
	int n, m, l, r;
	cin >> n >> m;

	bool **part = new bool *[m];
	for(int i = 0; i < m; i++)
		part[i] = new bool [n+1];
	int *t = new int [m];
	int *profit = new int [m];

	for(int i = 0; i < m; i++)
		for(int j = 1; j <= n; j++)
			part[i][j] = false;

	for(int i = 0; i < m; i++){
		cin >> l >> r >> t[i] >> profit[i];
		for(int j = l; j <= r; j++)
			part[i][j] = true;
	}

	long long int totalProfit = 0, minTime, maxProfit;
	for(int i = 1; i <= n; i++){
		minTime = -1;
		maxProfit = 0;
		for(int j = 0; j < m; j++)
			if(part[j][i]){
				if(t[j] < minTime || minTime < 0){
					minTime = t[j];
					maxProfit = profit[j];
				}
			}
		totalProfit += maxProfit;
	}
	cout << totalProfit << endl;
	return 0;
}