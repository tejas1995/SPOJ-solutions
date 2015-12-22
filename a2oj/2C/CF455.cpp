//http://codeforces.com/problemset/problem/455/A

#include <iostream>
#include <map>
using namespace std;

int main()
{
	long long int n, k;
	cin >> n;
	map<long long int, long long int> occ;
	long long int maxVal = -1;
	for(long long int i = 0; i < n; i++){
		cin >> k;
		occ[k]++;
		if(k > maxVal || maxVal < 0)
			maxVal = k;
	}
	long long int *score = new long long int [100005];
	score[0] = 0;
	for(long long int i = 1; i <= maxVal; i++)
	{
		if(occ.find(i) == occ.end())
		{
			score[i] = score[i-1];
		}
		else
		{
			if(i == 1){
				score[1] = occ[1];
				continue;
			}
			if(score[i-2]+i*occ[i] > score[i-1])
				score[i] = score[i-2]+i*occ[i];
			else
				score[i] = score[i-1];
		}
	}
	
	cout << score[maxVal] << endl;
	return 0;
}