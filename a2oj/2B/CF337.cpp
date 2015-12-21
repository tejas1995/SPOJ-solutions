//http://codeforces.com/problemset/problem/337/B

#include <iostream>
using namespace std;

int mod(int x)
{
	if(x < 0)
		return -x;
	else
		return x;
}

int gcd(int a, int b)
{
	int temp;
    while(a % b != 0){
    	temp = b;
    	b = a%b;
    	a = temp;
    }
    return b;
}

int main()
{
	int a, b, c, d, num, denom;
	cin >> a >> b >> c >> d;
	if(a*d > b*c){
		num = a*d - c*b;
		denom = a*d;
	}
	else{
		num = b*c - a*d;
		denom = b*c;
	}

	int e = gcd(num, denom);
	cout << num/e << "/" << denom/e << endl;
	return 0;
}