#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, k, l;
	cin >> n >> m;
	vector<int> *a = new vector<int> [n+1];
	for(int i = 0; i < m; i++)
	{
		cin >> k >> l;
		a[k].push_back(l);
		a[l].push_back(k);
	}

	int numOneLace = 0, numGroups = 0;
	int *removed = new int [n+1];

	do
	{
		for(int i = 1; i <= n; i++)
			removed[i] = 0;
		numOneLace = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].size() == 1 && removed[i] == 0)
			{
				k = a[i][0];
				a[k].erase(remove(a[k].begin(), a[k].end(), i), a[k].end());
				numOneLace++;
				a[i].erase(a[i].begin());
				removed[k] = 1;
			}
		}
		
		if(numOneLace > 0)
			numGroups++;
	}while(numOneLace > 0);
	cout << numGroups << endl;
	return 0;
}