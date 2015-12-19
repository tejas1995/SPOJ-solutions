//http://codeforces.com/problemset/problem/58/B

#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> var;

void findVar(int n)
{
	var.push_back(n);
	for(int i = 2; i <= n; i++)
	{
		if(n%i == 0)
			if(i == n){
				var.push_back(1);
				return;
			}
			else{
				findVar(n/i);
				return;
			}
	}
}

int main()
{
	int n;
	cin >> n;
	findVar(n);

	for(int i = 0; i < var.size(); i++)
		cout << var[i] << " ";
	cout << endl;
	return 0;
}