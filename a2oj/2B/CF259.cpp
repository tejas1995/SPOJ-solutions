//http://codeforces.com/problemset/problem/259/B

#include <iostream>
using namespace std;

bool check_magic(int sq[3][3], int sum)
{
	for(int i = 0; i < 3; i++)
		if(sq[i][0]+sq[i][1]+sq[i][2] != sum)
			return false;

	for(int i = 0; i < 3; i++)
		if(sq[0][i]+sq[1][i]+sq[2][i] != sum)
			return false;

	if(sq[0][0]+sq[1][1]+sq[2][2] != sum)
		return false;

	return true;
}
int main()
{
	int sq[3][3];
	for(int i=0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> sq[i][j];
	int sum;
	for(int i = 0; i <= 100000; i++)
	{
		sq[1][1] = i;
		sum = sq[0][2] + sq[1][1] + sq[2][0];
		sq[0][0] = sum - sq[0][2] - sq[0][1];
		sq[2][2] = sum - sq[2][0] - sq[2][1];
		if(check_magic(sq, sum))
		{
			for(int i=0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
					cout << sq[i][j] << " ";
				cout << endl;
			}
			return 0;
		}
	}

	return 0;
}