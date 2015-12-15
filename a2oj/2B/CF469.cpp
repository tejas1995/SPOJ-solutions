//http://codeforces.com/problemset/problem/469/B

#include <iostream>
using namespace std;

int main()
{
	int z[1005];
	
	int p, q, l, r;
	cin >> p >> q >> l >> r;

	int *a = new int [p];
	int *b = new int [p];
	int *c = new int [q];
	int *d = new int [q];
	bool foundTime;

	for (int i = 0; i < p; ++i)
		cin >> a[i] >> b[i];
	for(int i = 0; i < q; i++)
		cin >> c[i] >> d[i];

	int ans = 0;
	for(int i = l; i <= r; i++)
	{
		foundTime = false;
		for(int j = 0; j < p; j++){
			for(int k = 0; k < q; k++)
			{
				if(b[j] < i+c[k] || a[j] > i+d[k])
					continue;
				foundTime = true;
				ans++;
				break;
			}
			if(foundTime)
				break;
		}
	}
	cout << ans << endl;
}