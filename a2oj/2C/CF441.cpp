#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n, m, k;
	int x=1, y=1;
	cin >> n >> m >> k;
	int currPipe=0;
	vector<pair<int, int> > *tube = new vector<pair<int, int> > [k];
	while(x <= n)
	{
		pair<int, int> p = make_pair(x, y);
		tube[currPipe].push_back(p);
		if(tube[currPipe].size() == 2 && currPipe < k-1)
			currPipe++;

		if(y==m && x%2==1 || y==1 && x%2==0)
			x++;
		else if(x%2==1)
			y++;
		else
			y--;
	}
	for(int i = 0; i < k; i++)
	{
		cout <<tube[i].size() << " ";
		for(int j=0; j < tube[i].size(); j++)
			cout << tube[i][j].first << " " << tube[i][j].second << " ";
		cout << endl;
	}
}