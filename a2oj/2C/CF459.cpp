//http://codeforces.com/problemset/problem/459/C

#include <stdio.h>
#include <iostream>
using namespace std;

long long int pow(long long int k, long long int d){
	long long int p = 1;
	return p;
}

int bus[1002][1002];

int main()
{
	long long int n, k, d;
	cin >> n >> k >> d;
	long long int p = 1;
	bool poss = false;
	
	for(int i = 1; i <= d; i++){
		p *= k;
		if(p >= n){
			poss = true;
			break;
		}
	}
	
	if(!poss){
		printf("-1\n"); return 0;
	}

	for(int i = 0; i < d; i++){
		bus[0][i] = 0;
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < d; j++){
			bus[i][j] = bus[i-1][j];
		}
		int currD = d-1;
		do{
			bus[i][currD] = (bus[i][currD]+1)%k;
			currD--;
		}while(bus[i][currD+1] == 0 && currD >= 0);
	}

	for(int i = 0; i < d; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", bus[j][i]+1);
		printf("\n");
	}
	return 0;
}