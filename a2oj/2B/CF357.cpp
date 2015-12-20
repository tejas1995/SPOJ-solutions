//http://codeforces.com/problemset/problem/357/B

#include <iostream>
#include <map>
using namespace std;

int main()
{
	
	int n, m;
	cin >> n >> m;
	int *colour = new int [n+1];
	for(int i = 0; i <= n; i++)
		colour[i] = -1;
	for(int i = 0; i < m; i++){
		int a[3];
		for(int j = 0; j < 3; j++)
			cin >> a[j];
		int repCol = 0, currCol = 1;
		for(int j = 0; j < 3; j++)
			if(colour[a[j]] != -1){
				repCol = colour[a[j]];
			}
		while(currCol == repCol)
			currCol++;
		for(int j = 0; j < 3; j++){
			if(colour[a[j]] == -1){
				colour[a[j]] = currCol;
				currCol++;
				if(currCol == repCol)
					currCol++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << colour[i] << " ";
	cout << endl;
	return 0;
}