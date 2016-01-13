//http://codeforces.com/problemset/problem/14/B

#include <iostream>
using namespace std;

struct path{
	int l, u;
};

path intersection(path a, path b){
	int min, max;
	min = (a.l > b.l ? a.l : b.l);
	max = (a.u < b.u ? a.u : b.u);
	path tmp;
	tmp.l = min;
	tmp.u = max;
	return tmp;
}

int main()
{
	int n, x0, l, u;
	cin >> n >> x0;
	path *p = new path [n];
	for(int i = 0; i < n; i++){
		cin >> l >> u;
		if(l < u){
			p[i].l = l; p[i].u = u;
		}
		else{
			p[i].l = u; p[i].u = l;
		}
	}

	path inter = p[0];
	for(int i = 1; i < n; i++){
		inter = intersection(inter, p[i]);
		if(inter.l > inter.u){
			cout << "-1\n";
			return 0;
		}
	}
	if(x0 < inter.l)
		cout << inter.l - x0 << endl;
	else if(x0 > inter.u)
		cout << x0 - inter.u << endl;
	else
		cout << 0 << endl;
	return 0;
}