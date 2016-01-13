//http://codeforces.com/problemset/problem/374/B

#include <iostream>
#include <string>
using namespace std;

int ctoi(char c)
{
	return (int)c-48;
}

int main()
{
	string s;
	long long int prevNum, currNum;
	cin >> s;
	prevNum = ctoi(s[0]);
	int currLen = 0;
	long long int ans = 1, segAns=1;
	for(int i = 1; i < s.length(); i++){
		currNum = ctoi(s[i]);
		if(currNum + prevNum == 9){
			currLen++;
			if(i == s.length()-1){
				if(currLen%2 == 0)
					ans *= currLen/2+1;
			}
		}
		else{
			if(currLen%2 == 0 && currLen > 0)
				ans *= currLen/2+1;
			currLen = 0;
		}
		prevNum = currNum;
	}
	cout << ans << endl;
	return 0;
}