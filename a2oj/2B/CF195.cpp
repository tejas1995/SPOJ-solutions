//http://codeforces.com/problemset/problem/195/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int mod(float a){
	if(a < 0)
		return -a;
	else 
		return a;
}

bool sortVec(int a, int b){
	if(mod((m+1)/2.0-a) < mod((m+1)/2.0-b))
		return true;
	else if(mod((m+1)/2.0-a) == mod((m+1)/2.0-b) && a < b)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool start = true;
	vector<int> v;
	for(int i = 1; i <= m; i++)
		v.push_back(i);
	sort(v.begin(), v.end(), sortVec);
	for(int i = 0; i < n; i++)
		cout << v[i%m] << endl;
	return 0;
}