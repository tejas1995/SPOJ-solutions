//http://codeforces.com/problemset/problem/359/B

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int diff=0; 
	vector<int> seq;
	for(int i = 1; i <= n; i++)
	{
		if(diff < 2*k)
		{
			seq.push_back(2*i-1);
			seq.push_back(2*i);
			diff += 2;
		}
		else
		{
			seq.push_back(2*i);
			seq.push_back(2*i-1);
		}
	}
	for(vector<int>::iterator it=seq.begin(); it != seq.end(); it++)
		cout << *it << " ";
	cout << endl;
}