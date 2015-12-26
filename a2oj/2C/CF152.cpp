//http://codeforces.com/problemset/problem/152/C

#include <iostream>
#include <string>
using namespace std;

#define BIG 1000000007

int main()
{
	int n, m;
	cin >> n >> m;

	string *s = new string [n];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	long long int numComb = 1;
	for(int i = 0; i < m; i++){
		char let[26] = {0};
		long long int distinct = 0;
		for(int j = 0; j < n; j++){
			if(let[s[j][i]-'A'] == 0){
				let[s[j][i]-'A'] = 1;
				distinct++;
			}
		}
		numComb = (numComb*distinct)%BIG;
	}
		
	cout << numComb << endl;
	return 0;
}