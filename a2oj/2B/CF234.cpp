//http://codeforces.com/problemset/problem/234/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortThan(vector<int> v1, vector<int> v2)
{
	if(v1[1] > v2[1])
		return true;
	else
		return false;
}

int main()
{
	int n, t, k;
	cin >> n >> k;
	vector<int> *a = new vector<int> [n];
	for(int i = 0; i < n; i++){
		cin >> t;
		a[i].push_back(i+1);
		a[i].push_back(t);
	}	
	sort(a, a+n, sortThan);
	cout << a[k-1][1] << endl;
	for(int i = 0; i < k; i++)
		cout << a[i][0] << " ";
	cout << endl;
	return 0;
}