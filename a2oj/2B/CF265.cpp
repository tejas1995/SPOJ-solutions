//http://codeforces.com/problemset/problem/265/B

#include <iostream>
using namespace std;

int main()
{
	long long int n;
	long long int next_height, last_height;
	long long int time = 0;

	cin >> n;
	time += n + n-1;

	cin >> last_height;
	time += last_height;
	for(long long int i = 1; i < n; i++)
	{
		cin >> next_height;
		if(last_height > next_height)
			time += last_height - next_height;
		else
			time += next_height - last_height;
		last_height = next_height;
	}

	cout << time << endl;
	return 0;
}