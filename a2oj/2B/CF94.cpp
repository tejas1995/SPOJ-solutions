//http://codeforces.com/problemset/problem/94/B

#include <iostream>
using namespace std;

int main()
{
	int m;
	bool fr[6][6] = {false};
	cin >> m;
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		fr[x][y] = true;
		fr[y][x] = true;
	}

	bool know=false, dunno=false;
	for(int i = 1; i <= 5; i++){
		for(int j = i+1; j <= 5; j++){
			if(fr[i][j])
				for(int k = j+1; k <= 5; k++)
					if(fr[i][k] && fr[j][k] && k!=i && k!=j){
						cout << "WIN\n";
						return 0;
					}
		}
	}

	for(int i = 1; i <= 5; i++){
		for(int j = i+1; j <= 5; j++){
			if(!fr[i][j])
				for(int k = 1; k <= 5; k++)
					if(!fr[i][k] && !fr[j][k] && k!=i && k!=j){
						cout << "WIN\n";
						return 0;
					}
		}
	}
	cout << "FAIL\n";
	return 0;
}