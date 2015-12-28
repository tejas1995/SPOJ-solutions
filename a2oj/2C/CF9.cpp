//http://codeforces.com/problemset/problem/9/C

#include <iostream>
using namespace std;

int digits(int n)
{
	int dig = 0;
	while(n > 0){
		n /= 10;
		dig++;
	}
	return dig;
}

long long int pow(int a, int b)
{
	int ans = 1;
	for(int i = 1; i <= b; i++)
		ans *= a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	int mult=1, numWays=0;
	while(n > 0){
		if(n%10 > 1){
			numWays = 2*mult-1;
		}
		else if(n%10 ==1)
			numWays += mult;
		mult *= 2;
		n /= 10;
	}
	cout << numWays << endl;
	return 0;
}