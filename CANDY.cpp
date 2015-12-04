#include <iostream>
using namespace std;

typedef unsigned long long int uLong;

int main()
{
	int N;

	while(true)
	{
		cin >> N;

		if(N == -1)
			break;
		else
		{
			int *candy = new int [N];

			for(int i = 0; i < N; i++)
				cin >> candy[i];

			uLong totalCandies = 0;
			for(int i = 0; i < N; i++)
				totalCandies += candy[i];

			if(totalCandies % N != 0)
			{
				cout << -1 << endl;
			}
			else
			{
				int candyPerPacket = totalCandies/N;

				uLong diffToMean = 0;
				for(int i = 0; i < N; i++)
					if(candy[i] > candyPerPacket)
						diffToMean += candy[i] - candyPerPacket;
					else
						diffToMean += candyPerPacket - candy[i];

				cout << diffToMean/2 << endl;
			}
		}
	}

	return 0;
}