//http://codeforces.com/problemset/problem/330/B

#include <iostream>
using namespace std;

int main()
{
	int n, m, ai, bi;
	cin >> n >> m;
	int *city = new int [n+1];
	for(int i = 0; i <= n; i++)
		city[i] = 1;
	for(int i = 0; i < m; i++){
		cin >> ai >> bi;
		if(city[ai] == 1)
			city[ai] = 0;
		if(city[bi] == 1)
			city[bi] = 0;
	}
	int center = 1;
	while(city[center] == 0 && center <= n)
		center++;
	cout << n-1 << endl;
	for(int i = 1; i <= n; i++){
		if(i != center)
			cout << i << " " << center << endl;
	}
}