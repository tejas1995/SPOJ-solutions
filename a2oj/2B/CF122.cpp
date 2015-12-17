//http://codeforces.com/problemset/problem/122/B

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int num4 = 0, num7 = 0;
	for(int i = 0; i < s.length(); i++)
		if(s[i] == '4')
			num4++;
		else if(s[i] == '7')
			num7++;

	if(num4 == 0 && num7 == 0)
		cout << "-1\n";
	else if(num4 >= num7)
		cout << "4\n";
	else
		cout << "7\n";
	return 0;
}