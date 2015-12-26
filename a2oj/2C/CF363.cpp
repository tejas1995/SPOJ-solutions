//http://codeforces.com/problemset/problem/363/C

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, ans;
	cin >> s;
	int ansLen = 0;
	ans.push_back(s[0]);
	ansLen++;
	if(s.length() > 1){
		ans.push_back(s[1]);
		ansLen++;
	}
	for(int i = 2; i < s.length(); i++){
		if(s[i] == ans[ansLen-1] && s[i] == ans[ansLen-2])
			continue;
		else if(ansLen > 2)
			if(s[i] == ans[ansLen-1] && ans[ansLen-2] == ans[ansLen-3])
				continue;
		ans.push_back(s[i]);
		ansLen++;
	}
	cout << ans << endl;
	return 0;
}