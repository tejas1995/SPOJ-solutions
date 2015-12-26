//http://codeforces.com/problemset/problem/486/C

#include <iostream>
#include <string>
using namespace std;

int modDiff(int a, int b)
{
	if(a > b)
		return a-b;
	else
		return b-a;
}

int main()
{
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	int mid = n/2;
	if(p > mid)
		p = n-p+1;

	int numPress = 0;
	int firstDiff=-1, lastDiff=-1;
	bool foundDiff = false;
	for(int i=0, j=s.length()-1; i < mid; i++, j--){
		if(s[i] != s[j]){
			if(foundDiff == false){
				foundDiff = true;
				firstDiff = i;
			}
			lastDiff = i;
		}
		if(modDiff(s[i], s[j]) > 13)
			numPress += 26 - modDiff(s[i], s[j]);
		else
			numPress += modDiff(s[i], s[j]);
	}

	if(firstDiff == -1 && lastDiff == -1){
		cout << numPress << endl; return 0;
	}
	if(firstDiff >= p-1){
		numPress += lastDiff - (p-1);
	}
	else if(lastDiff <= p-1)
	{
		numPress += p-1 - firstDiff;
	}
	else if(firstDiff < p-1 && lastDiff > p-1){
		if(p-1-firstDiff < lastDiff-(p-1))
			numPress += p-1-firstDiff + lastDiff-firstDiff;
		else
			numPress += lastDiff-(p-1) + lastDiff-firstDiff;
	}
	cout << numPress << endl;
	return 0;
}