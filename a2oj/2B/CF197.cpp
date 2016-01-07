//http://codeforces.com/problemset/problem/197/B

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int *a = new int [n+1];
	int *b = new int [m+1];
	for(int i = 0; i <= n; i++)
		cin >> a[i];
	for(int i = 0; i <= m; i++)
		cin >> b[i];

	if(n == m){
		bool neg = (a[0]*b[0] > 0 ? false : true);
		int x = (a[0] > 0 ? a[0] : -a[0]);
		int y = (b[0] > 0 ? b[0] : -b[0]);
		int curr = 2;
		while(curr <= x && curr <= y){
			if(x%curr == 0 && y%curr == 0){
				x /= curr;
				y /= curr;
			}
			else
				curr++;
		}
		if(neg)
			cout << "-";
		cout << x << "/" << y << endl;
	}
	else if(n > m){
		if(a[0]*b[0] > 0)
			cout << "Infinity" << endl;
		else
			cout << "-Infinity" << endl;
	}
	else
		cout << "0/1" << endl;
	return 0;
}