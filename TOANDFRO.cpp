#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int N, length;
	char input[200];
	do
	{
		cin >> N;
		cin.ignore();

		if(N != 0)
		{
			
			int i, j;

			cin.getline(input, 200);
			length = strlen(input);
			
			char **code_string = new char *[length/N];
			for(i = 0; i < length/N; i++)
				code_string[i] = new char [N];

			int direction=1, row=0;
			for(i = 0, j = 0; i < length; i++)
			{
				code_string[row][j] = input[i];

				if(j == N-1 && direction == 1)
				{
					row++;
					direction = -1;
				}
				else
				if(j == 0 && direction == -1)
				{
					row++;
					direction = 1;
				}
				else
					j += direction;
			}

			for(i = 0; i < N; i++)
				for(j = 0; j < length/N; j++)
					cout << code_string[j][i];

			for(i = 0; i < length/N; i++)
				delete [] code_string[i];
		}
		cout << endl;

	} while(N);

	return 0;
}