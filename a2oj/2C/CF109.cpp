//http://codeforces.com/problemset/problem/109/A

#include <iostream>
using namespace std;

bool checkLucky(int n)
{
	while(n > 0)
	{
		if(n%10 != 4 && n%10 != 7)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int numSeven = n/7;
	int rem = n%7;
	int numFour = rem/4;
	bool poss=false;
	do{
		if(rem % 4 == 0){
			numFour = rem/4;
			poss = true;
			break;
		}
		numSeven--;
		rem += 7;
	}while(numSeven >= 0);
	if(!poss)
	{
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < numFour; i++)
		cout << "4";
	for(int i = 0; i < numSeven; i++)
		cout << "7";
	cout << endl;
	return 0;
}