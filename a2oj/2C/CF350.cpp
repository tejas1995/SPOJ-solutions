//http://codeforces.com/problemset/problem/350/C

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int mod(int n){
	if(n < 0)
		return -n;
	else
		return n;
}

bool sortV(vector<int> v1, vector<int> v2){
	int a = mod(v1[0])+mod(v1[1]), b = mod(v2[0])+mod(v2[1]);
	if(a < b)
		return true;
	else if(a == b && mod(v1[1]) < mod(v2[1]))
		return true;
	return false;
}

int main()
{
	int n, p, q;
	scanf("%d", &n);
	vector<int> *v = new vector<int> [n];
	for(int i = 0; i < n; i++){
		scanf("%d %d", &p, &q);
		v[i].push_back(p);
		v[i].push_back(q);
	}
	sort(v, v+n, sortV);
	int numMoves = 0;
	for(int i = 0; i < n; i++){
		if(v[i][0] != 0)
			numMoves += 2;
		if(v[i][1] != 0)
			numMoves += 2;
		numMoves += 2; //Operation 2 & 3
	}
	printf("%d\n", numMoves);
	for(int i = 0; i < n; i++){
		if(mod(v[i][1]) != 0){
			if(v[i][1] > 0)
				printf("1 %d U\n", mod(v[i][1]));
			else
				printf("1 %d D\n", mod(v[i][1]));
		}
		if(mod(v[i][0]) != 0){
			if(v[i][0] > 0)
				printf("1 %d R\n", mod(v[i][0]));
			else
				printf("1 %d L\n", mod(v[i][0]));
		}
		printf("2\n");
		if(mod(v[i][0]) != 0){
			if(v[i][0] > 0)
				printf("1 %d L\n", mod(v[i][0]));
			else
				printf("1 %d R\n", mod(v[i][0]));
		}
		if(mod(v[i][1]) != 0){
			if(v[i][1] > 0)
				printf("1 %d D\n", mod(v[i][1]));
			else
				printf("1 %d U\n", mod(v[i][1]));
		}
		printf("3\n");
	}
}