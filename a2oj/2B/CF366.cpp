//http://codeforces.com/problemset/problem/366/B

#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int *a = new int [n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int minPower=-1, bestStart=-1;
	for(int i = 0; i < k; i++){
		int sum = 0;
		for(int j = 0; j < n; j+=k)
			sum += a[i+j];
		if(sum < minPower || minPower < 0){
			minPower = sum;
			bestStart = i+1;
		}
	}
	cout << bestStart << endl;
	return 0;
}