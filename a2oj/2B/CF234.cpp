//http://codeforces.com/problemset/problem/234/B

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool sortThan(vector<int> v1, vector<int> v2)
{
	if(v1[1] > v2[1])
		return true;
	else
		return false;
}

int main()
{
	int n, t, k;
	FILE *inputFile; FILE *outputFile;
    inputFile  = fopen("input.txt", "r"); 
    outputFile = fopen("output.txt", "w");

	fscanf(inputFile, "%d %d", &n, &k);
	vector<int> *a = new vector<int> [n];
	for(int i = 0; i < n; i++){
		fscanf(inputFile, "%d", &t);
		a[i].push_back(i+1);
		a[i].push_back(t);
	}	
	sort(a, a+n, sortThan);
	
	fprintf(outputFile, "%d\n", a[k-1][1]);
	for(int i = 0; i < k; i++)
		fprintf(outputFile, "%d ", a[i][0]);
	fprintf(outputFile,"\n");
	return 0;
}