//http://codeforces.com/problemset/problem/342/B

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n, m, s, f, add;
	char st='X', move;
	cin >> n >> m >> s >> f;
	if(f > s){
		move='R';
		add=1;
	}
	else{
		move='L';
		add=-1;
	}
	int t, l, r;
	map<int, vector<int> > tRange;
	for(int i = 0; i < m; i++){
		cin >> t >> l >> r;
		tRange[t].push_back(l);
		tRange[t].push_back(r);
	}
	int curr = s;
	t = 1;
	while(curr != f)
	{
		if(tRange.find(t) == tRange.end()){
			cout << move;
			curr = curr + add;
		}
		else{
			if((curr < tRange[t][0] || curr > tRange[t][1]) && (curr+add < tRange[t][0] || curr+add > tRange[t][1])){
				cout << move;
				curr = curr + add;
			}
			else{
				cout << st;
			}
		}
		t++;
	}
	cout << endl;
	return 0;

}