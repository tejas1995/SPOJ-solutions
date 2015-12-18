//http://codeforces.com/problemset/problem/133/B

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char, int> bin;
	bin['>'] = 8;
	bin['<'] = 9;
	bin['+'] = 10;
	bin['-'] = 11;
	bin['.'] = 12;
	bin[','] = 13;
	bin['['] = 14;
	bin[']'] = 15;

	string s;
	cin >> s;
	int op = 0;
	for(int i=0; i < s.length(); i++){
		int val = bin[s[i]];
		op = (op*16 + val)%1000003;
	}
	cout << op << endl;
	return 0;
}