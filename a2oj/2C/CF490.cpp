//http://codeforces.com/problemset/problem/490/C

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	string code;
	int a, b, dig, i, j, k, p;
	cin >> code;
	cin >> a >> b;
	int mod=0;
	vector<int> prefixPos, suffixPos;
	for(int i = 0; i < code.length()-1; i++)
	{
		dig = code[i]-48;
		mod = (10*mod + dig)%a;
		if(mod == 0)
			prefixPos.push_back(i);
	}
	
	long long int mult = 1;
	mod=0;
	for(i = code.length()-1; i >= 0; i--)
	{
		dig = code[i]-48;
		mod = (dig*mult + mod)%b;
		if(mod == 0)
			suffixPos.push_back(i-1);
		mult = (mult*10)%b;
	}
	
	for(i = 0; i < prefixPos.size(); i++)
	{
		int p = prefixPos[i];
		if(find(suffixPos.begin(), suffixPos.end(), p) != suffixPos.end() && code[p+1] != '0')
		{
			cout << "YES\n";
			for(k=0; k <= p; k++)
				cout << code[k];
			cout << endl;
			for(k=p+1; k < code.length(); k++)
				cout << code[k];
			cout << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}