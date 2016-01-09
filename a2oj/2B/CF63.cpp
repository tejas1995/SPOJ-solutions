//http://codeforces.com/problemset/problem/63/B

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n, k, x;
	cin >> n >> k;
	int *count = new int [k+5];
	for(int i = 0; i < k+5; i++)
		count[i] = 0;

	for(int i = 0; i < n; i++){
		cin >> x;
		count[x]++;
	}
	int coins = 0;
	while(count[k] != n){
		for(int i = k-1; i >= 1; i--){
			if(count[i] > 0){
				count[i+1]++;
				count[i]--;
			}
		}
		coins++;
	}
	cout << coins << endl;
	return 0;
}