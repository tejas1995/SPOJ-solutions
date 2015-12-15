//http://codeforces.com/problemset/problem/432/B

#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, h, a;
	cin >> n;
	map<int, int> home;
	int away[100000];
	for(int i = 0; i < n; i++)
	{
		cin >> h >> a;
		if(home.find(h) == home.end())
			home[h] = 1;
		else
			home[h] += 1;
		away[i] = a;
	}

	for(int i = 0; i < n; i++)
	{
		if(home.find(away[i]) == home.end())
			cout << n-1 << " " << n-1 << endl;
		else
			cout << n-1+home[away[i]] << " " << n-1-home[away[i]] << endl;
	}
	return 0;
}