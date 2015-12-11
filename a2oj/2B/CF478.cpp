//http://codeforces.com/problemset/problem/478/B

#include <iostream>
using namespace std;

int main()
{
	long long int n, m, minPairs, maxPairs;
	cin >> n >> m;

	long long int teamsWithNDivM = m - n%m, teamsWithNDivMPlus1 = n%m;

	minPairs = teamsWithNDivM*(n/m)*(n/m-1)/2 + teamsWithNDivMPlus1*(n/m+1)*(n/m)/2;
	maxPairs = (n-m+1)*(n-m)/2;
	cout << minPairs << " " << maxPairs << endl;
}