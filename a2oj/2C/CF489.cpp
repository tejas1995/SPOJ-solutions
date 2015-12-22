//http://codeforces.com/problemset/problem/489/C

#include <iostream>
using namespace std;

int main()
{
	int m, s;
	cin >> m >> s;
	if(s > 9*m || (s == 0 && m>1)){
		cout << "-1 -1\n";
		return 0;
	}
	int sum = s;
	for(int i = 0; i < m; i++)
	{
		for(int d=0; d < 10; d++){
			if((i > 0 || d > 0 || (m==1 && d==0)) && (sum-d <= (m-i-1)*9 && sum-d >= 0))
			{
				cout << d;
				sum -= d;
				break;
			}
		}
	}
	cout << " ";
	
	for(int i = 0; i < m; i++)
	{
		for(int d = 9; d >= 0; d--)
			if(s-d <= (m-i-1)*9 && s-d >= 0){
				cout << d;
				s -= d;
				break;
			}
	}
	cout << endl;
	return 0;
}