//http://codeforces.com/problemset/problem/219/B

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int uLong;

int numDigits(uLong n)
{
	uLong op = 0;
	while(n > 0)
	{
		n /= 10;
		op++;
	}
	return op;
}

uLong kLimit(uLong p)
{
	uLong k = 1;
	while(p%10 == 9){
		p /= 10;
		k *= 10;
	}
	return k;
}

int main()
{
	uLong p, d, k;
	cin >> p >> d;
	k = 1;
	for(int i = 1; i <= numDigits(p)-1; i++)
		k *= 10;
	uLong lim = kLimit(p);
	for(; k > lim; k /= 10)
	{
		uLong ans = p - p%k - 1;
		if(ans != -1 && ans >= p-d){
			cout << ans << endl;
			return 0;
		}
	}
	cout << p << endl;
	return 0;
}