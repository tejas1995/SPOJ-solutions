//http://codeforces.com/problemset/problem/282/B

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a, g;
	int sa=0, sg=0;
	for(int i = 0; i < n; i++){
		cin >> a >> g;
		if(sa+a-sg <= 500){
			cout << "A";
			sa += a;
		}
		else{
			cout << "G";
			sg += g;
		}
	}
	cout << endl;
	return 0;
}