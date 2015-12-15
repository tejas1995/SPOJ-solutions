//http://codeforces.com/problemset/problem/486/B

#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int A[100][100], B[100][100];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			A[i][j] = 1;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			cin >> B[i][j];
			if(B[i][j] == 0)
			{
				for(int k = 0; k < n; k++)
					A[i][k] = 0;
				for(int k = 0; k < m; k++)
					A[k][j] = 0;
			}
		}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			if(B[i][j] == 1)
			{
				bool allZero = true;
				for(int k = 0; k < n; k++)
					if(A[i][k] == 1)
					{
						allZero = false;
						break;
					}
				for(int k = 0; k < m; k++)
					if(A[k][j] == 1)
					{
						allZero = false;
						break;
					}

				if(allZero == true)
				{
					cout << "NO\n";
					return 0;	
				}
			}
		}

	cout << "YES\n";
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}