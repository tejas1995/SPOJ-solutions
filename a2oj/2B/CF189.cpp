//http://codeforces.com/problemset/problem/189/B

#include <iostream>
using namespace std;

int main()
{
	long long int ans=0;
	int H, W;
	cin >> H >> W;
	for(int h = 2; h <= H; h+=2)
		for(int w = 2; w <= W; w+=2){
			ans += (H-h+1)*(W-w+1);
		}
	cout << ans << endl;
	return 0;
}