#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef unsigned long long int uLong;

int main()
{
	uLong t, m, n;

	cin >> t;

	uLong *mList = new uLong [t];
	uLong *nList = new uLong [t];

	for(uLong i = 0; i < t; i++)
	{
		cin >> mList[i] >> nList[i];
	}

	int lenPE = int(sqrt(pow(10, 9)));
	int precompPrimes[lenPE];
	for(int i = 0; i < lenPE; i++)
		precompPrimes[i] = 0;

	for (int j = 2; j <= lenPE; j++)
	{
		if(precompPrimes[j-1] == 0)
		    for (uLong k = j * j; k <= lenPE; k += j)
		    {
		        precompPrimes[k - 1] = 1;
		    }
	}
	
	for(uLong i = 0; i < t; i++)
	{
		m = mList[i];
		n = nList[i];

	    for (uLong j = m; j <= n; j++)
	    {
	    	//cout << "j :" << j << endl;
	    	int prime = 1;

	    	for(int k = 2; k < lenPE && k < j; k++)
	    		if(precompPrimes[k-1] == 0)
	    		{
	    			//cout << "k : " << k << endl;
	    			if(j % k == 0)
	    			{
	    				prime = 0;
	    				break;
	    			}
	    		}
	    		
	    	if(prime == 1 && j != 1)
	    		cout << j << endl;
	    }
		cout << endl;
	}
}