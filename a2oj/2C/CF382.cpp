//http://codeforces.com/problemset/problem/382/C

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a = new int [n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);

	if(n==1){
		cout << "-1\n"; return 0;
	}
	if(n==2){
		vector<int> v;
		int d = a[1]-a[0];

		v.push_back(a[0]-d);
		if(d != 0)
			v.push_back(a[1]+d);
		if((a[0]+a[1])%2 == 0 && d != 0)
			v.push_back((a[1]+a[0])/2);
		sort(v.begin(), v.end());
		cout << v.size() << endl;
		for(int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		return 0;
	}

	int d=-1;
	for(int i = 1; i < n; i++)
		if(a[i]-a[i-1] < d || d < 0)
			d = a[i]-a[i-1];

	for(int i = 1; i < n; i++)
		if(a[i] != a[i-1])
			break;
		else if(i == n-1){
			cout << "1\n" << a[0] << endl; return 0;
		}
	bool isAP = true;
	int numGap = 0, gapIndex;
	for(int i = 1; i < n; i++){
		if(a[i]-a[i-1] == d)
			continue;
		else if(a[i]-a[i-1] == 2*d){
			numGap++; gapIndex=i;
		}
		else{
			isAP = false;
			break;
		}
	}
	if(numGap == 1 && isAP == true){
		cout << "1\n" << (a[gapIndex]+a[gapIndex-1])/2 << endl; return 0;
	}
	else if(isAP == false || numGap > 1){
		cout << "0\n"; return 0;
	}
	else{
		cout << "2\n";
		cout << a[0]-d << " " << a[n-1]+d << endl;
		return 0;
	}
}