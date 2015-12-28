//http://codeforces.com/problemset/problem/339/C

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Type{
	int depth, balance, val, prevnode;
};

bool visited [1001][21][11] = {false};
Type Q[300000];
int w[11] = {0};

int main()
{
	int m;
	char c;
	for(int i = 1; i <= 10; i++){
		cin >> c;
		if(c=='1')
			w[i] = 1;
	}
	cin >> m;

	Type t; t.depth = 0; t.balance=10; t.val = 0; t.prevnode = 0;
	visited[0][10][0] = true;
	int head=0, tail=0;
	Q[tail++] = t;
	bool found = false;
	while(head < tail){
		Type temp = Q[head++];
		for(int i = 1; i <= 10; i++){
			if(w[i] && i != temp.val){
				Type next;
				next.depth = temp.depth+1;
				next.balance = (temp.depth%2 == 0 ? temp.balance+i : temp.balance-i);
				next.val = i;
				next.prevnode = head-1;

				if((temp.balance < 10 && next.balance > 10) || (temp.balance > 10 && next.balance < 10) || temp.balance == 10){
					if(!visited[next.depth][next.balance][next.val]){
						visited[next.depth][next.balance][next.val] = true;
						Q[tail++] = next;
						if(next.depth == m){
							found = true; break;
						}
					}
				}
			}
		}
		if(found)
			break;
	}

	if(found){
		cout << "YES\n";
		int ans[1000], nans = 0;
		int now = tail-1;
		while (now > 0){
			ans[nans++] = Q[now].val;
			now = Q[now].prevnode;
		}
		for(int i = nans-1; i >= 0; i--){
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;
	}
	cout << "NO\n";
	return 0;

}