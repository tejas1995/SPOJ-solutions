//http://codeforces.com/problemset/problem/416/B

#include <iostream>
using namespace std;

int main()
{
	int fin[50005][5], t[5];
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i];
		if(i == 0)
			fin[0][i] = t[i];
		else
			fin[0][i] = fin[0][i-1] + t[i];
	}

	for(int i = 1; i < m; i++)
		for(int j = 0; j < n; j++){
			cin >> t[j];
			if(j == 0){
				fin[i][j] = fin[i-1][j] + t[j];
			}
			else{
				if(fin[i-1][j] > fin[i][j-1])
					fin[i][j] = fin[i-1][j] + t[j];
				else
					fin[i][j] = fin[i][j-1] + t[j];
			}
		}
	for(int i = 0; i < m; i++)
		cout << fin[i][n-1] << " ";
	cout << endl;
	return 0;
}