//http://codeforces.com/problemset/problem/320/B

#include <iostream>
#include <vector>
using namespace std;

struct interval{
	int l, r;
	vector<int> dest;
};

bool canTravel(interval a, interval b){
	if((a.l > b.l && a.l < b.r) || (a.r > b.l && a.r < b.r))
		return true;
	else
		return false;
}

int main()
{
	int n, l, r, cmd, numInt=0, head, tail;
	cin >> n;
	vector<interval> intList;
	vector<interval> Q;

	for(int k = 0; k < n; k++){
		cin >> cmd >> l >> r;
		if(cmd == 1){
			interval i;
			i.l = l; i.r = r;
			intList.push_back(i);
			for(int i = 0; i < numInt; i++){
				if(canTravel(intList[i], intList[numInt]))
					intList[i].dest.push_back(numInt);
				if(canTravel(intList[numInt], intList[i]))
					intList[numInt].dest.push_back(i);
			}
			numInt++;
		}
		if(cmd == 2){
			bool visited[105] = {false};
			interval init = intList[l-1];
			visited[l-1] = true;
			head=0; tail=0;
			Q.push_back(init);
			while(Q.size() != 0){
				interval temp = Q[0];
				Q.erase(Q.begin());
				for(int i = 0; i < temp.dest.size(); i++){
					if(visited[temp.dest[i]] == true)
						continue;
					Q.push_back(intList[temp.dest[i]]);
					visited[temp.dest[i]] = true;
				}
			}
			Q.clear();
			if(visited[r-1] == true)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}