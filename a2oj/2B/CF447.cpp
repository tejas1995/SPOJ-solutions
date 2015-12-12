//http://codeforces.com/problemset/problem/447/B

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string s;
	int n, k, maxVal=0;
	cin >> s;
	cin >> k;
	map<char, int> val;
	for(char i = 'a'; i <= 'z'; i++)
	{
		cin >> n;
		val[i] = n;
		if(maxVal < n)
			maxVal = n;
	}
	int maxSum = 0;
	for(int i = 0; i < s.length(); i++)
		maxSum += (i+1)*val[s[i]];
	maxSum += maxVal*(k*s.length() + k*(k+1)/2);
	cout << maxSum << endl;

}