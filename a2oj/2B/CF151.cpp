//http://codeforces.com/problemset/problem/151/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct Friend
{
	string name;
	int app;
	int pizza;
	int taxi;
	int girls;
};

bool sortPizza(Friend f1, Friend f2)
{
	if(f1.pizza > f2.pizza)
		return true;
	else if(f1.pizza == f2.pizza && f1.app < f2.app)
		return true;
	else
		return false;
}

bool sortTaxi(Friend f1, Friend f2)
{
	if(f1.taxi > f2.taxi)
		return true;
	else if(f1.taxi == f2.taxi && f1.app < f2.app)
		return true;
	else
		return false;
}

bool sortGirls(Friend f1, Friend f2)
{
	if(f1.girls > f2.girls)
		return true;
	else if(f1.girls == f2.girls && f1.app < f2.app)
		return true;
	else
		return false;
}

int getType(string s)
{
	int lastDig = s[0];
	for(int i = 1; i < s.length(); i++)
		if(s[i] == '-')
			continue;
		else if(s[i] < lastDig){
			lastDig = s[i];
			if(i == s.length()-1)
				return 1;
		}
		else
			break;
	for(int i = 0; i < s.length(); i++)
		if(s[i] != '-' && s[i] != s[0])
			break;
		else if(i == s.length()-1)
			return 2;

	return 3;
}

int main()
{
	int n;
	cin >> n;

	Friend *f = new Friend [n];
	for(int i = 0; i < n; i++)
	{
		int s;
		cin >> s;
		cin >> f[i].name;
		f[i].app = i;
		f[i].pizza = 0; f[i].taxi = 0; f[i].girls = 0;
		for(int j = 0; j < s; j++)
		{
			string num;
			cin >> num;
			int type = getType(num);
			if(type == 1)
				f[i].pizza++;
			else if(type == 2)
				f[i].taxi++;
			else
				f[i].girls++;
		}
	}

	sort(f, f+n, sortTaxi);
	cout << "If you want to call a taxi, you should call: " << f[0].name;
	for(int i = 1; f[i].taxi == f[0].taxi && i < n; i++)
		cout << ", " << f[i].name;
	cout << ".\n";

	sort(f, f+n, sortPizza);
	cout << "If you want to order a pizza, you should call: " << f[0].name;
	for(int i = 1; f[i].pizza == f[0].pizza && i < n; i++)
		cout << ", " << f[i].name;
	cout << ".\n";

	sort(f, f+n, sortGirls);
	cout << "If you want to go to a cafe with a wonderful girl, you should call: " << f[0].name;
	for(int i = 1; f[i].girls == f[0].girls && i < n; i++)
		cout << ", " << f[i].name;
	cout << ".\n";
	return 0;
}