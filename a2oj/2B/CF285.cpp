//http://codeforces.com/problemset/problem/285/B

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, s, t, k;
	vector<int> switchVec;
	cin >> n >> s >> t;

	for(int i = 0; i < n; i++)
	{
		cin >> k;
		switchVec.push_back(k);
	}

	int currPos = s, i=0;
	do
	{
		if(currPos == t)
		{
			cout << i << endl;
			return 0;
		}
		currPos = switchVec[currPos-1];
		i++;
	}while(i < n);

	cout << "-1\n";
	return 0;
}