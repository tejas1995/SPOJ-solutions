//http://codeforces.com/problemset/problem/233/B

#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned long long int uLong;

int s(int n)
{
	int sum = 0;
	while(n > 0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main()
{
	uLong n;
	cin >> n;
	uLong minTest = (sqrt(n) >= 91) ? sqrt(n)-90 : 1;
	uLong maxTest = sqrt(n);
	long long int ans = -1;
	for(uLong i = minTest; i <= maxTest; i++)
		if(i*i+s(i)*i == n){
			ans = i;
			break;
		}
	cout << ans << endl;
	return 0;
}