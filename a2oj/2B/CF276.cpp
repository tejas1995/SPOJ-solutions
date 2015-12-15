//http://codeforces.com/problemset/problem/276/B

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	string s;
	cin >> s;

	set<char> odd;
	for(int i = 0; i < s.length(); i++)
		if(odd.find(s[i]) == odd.end())
			odd.insert(s[i]);
		else
			odd.erase(odd.find(s[i]));

	if(odd.size() == 0)
		cout << "First\n";
	else if((odd.size())%2 == 1)
		cout << "First\n";
	else
		cout << "Second\n";

	return 0;
}