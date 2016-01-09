//http://codeforces.com/problemset/problem/225/B

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void calc(int s, int k){
	v.push_back(1);
	v.push_back(1);
	int tmp = 1, a=1;
	while(true){
		a++;
		if(a <= k)
			tmp *= 2;
		else
			tmp = v[a-1]*2 - v[a-1-k];
		if(tmp > s)
			break;
		v.push_back(tmp);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int s, k;
	cin >> s >> k;
	calc(s, k);
	int len = v.size();
	vector<int> ans;
	bool *free = new bool [len+5];
	for(int i = 0; i < len+5; i++)
		free[i] = true;

	while(s){
		for(int i = len-1; i >= 0; i--){
			if(ans.size() == 0 && v[i] == s){
				ans.push_back(0);
				ans.push_back(v[i]);
				s = 0;
			}
			if(v[i] <= s && free[i] == true){
				s -= v[i];
				ans.push_back(v[i]);
				free[i] = false;
			}
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}