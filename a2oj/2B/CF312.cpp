//http://codeforces.com/problemset/problem/312/B

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double f1 = (double)a/b, f2 = (double)c/d;
	double num = f1;
	double denom = 1-(1-f1)*(1-f2);
	double ans = num/denom;
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}