//http://codeforces.com/problemset/problem/220/A

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a = new int [n];
	int *b = new int [n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b+n);
	vector<int> v;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i])
			v.push_back(i);
	}

	if(v.size() == 0){
		cout << "YES\n";
	}
	else if(v.size() == 2 && a[v[0]] == b[v[1]] && a[v[1]] == b[v[0]]){
		cout << "YES\n";
	}
	else
		cout << "NO\n";
	return 0;
}