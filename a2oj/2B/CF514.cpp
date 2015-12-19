//http://codeforces.com/problemset/problem/514/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, x0, y0, x, y;
	cin >> n >> x0 >> y0;
	vector<double> slope;
	bool slopeInf = false;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if(x == x0){
			slopeInf = true;
			continue;
		}
		double s = ((double)y-y0)/(x-x0);
		if(find(slope.begin(), slope.end(), s) == slope.end())
			slope.push_back(s);
	}
	if(slopeInf)
		cout << slope.size()+1 << endl;
	else
		cout << slope.size() << endl;
	return 0;
}