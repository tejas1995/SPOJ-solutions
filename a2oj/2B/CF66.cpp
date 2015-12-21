//http://codeforces.com/problemset/problem/66/B

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *h = new int [n];
	for(int i = 0; i < n; i++)
		cin >> h[i];
	int maxWet = 0;
	int left = 0, right = 0;
	while(h[right] >= h[right+1] && right < n-1)
		right++;
	maxWet = right+1;
	for(int i = 1; i < n; i++)
	{
		if(h[i] < h[i-1])
			left = 0;
		else
			left++;
		right = 0;
		int j = i;
		while(h[j] >= h[j+1] && j < n-1){
			right++; j++;
		}
		if(left + right + 1 > maxWet)
			maxWet = left + right + 1;
	}
	cout << maxWet << endl;
}