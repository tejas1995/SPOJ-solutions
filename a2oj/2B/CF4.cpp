//http://codeforces.com/problemset/problem/4/B

#include <iostream>
using namespace std;

int main()
{
	int d, sumTime, minTotal=0, maxTotal=0;
	cin >> d >> sumTime;
	int *min = new int [d];
	int *max = new int [d];
	for(int i = 0; i < d; i++)
	{
		cin >> min[i] >> max[i];
		minTotal += min[i];
		maxTotal += max[i];
	}
	if(sumTime < minTotal || sumTime > maxTotal){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";

	int *schedule = new int [d];
	for(int i = 0; i < d; i++)
		schedule[i] = min[i];
	int rem = sumTime - minTotal, curr=0;
	while (rem > 0){
		if(rem >= max[curr]-min[curr]){
			schedule[curr] += max[curr] - min[curr];
			rem -= max[curr]-min[curr];
			curr++;
		}
		else{
			schedule[curr] += rem;
			rem = 0;
		}
	}
	for(int i = 0; i < d; i++)
		cout << schedule[i] << " ";
	cout << endl;
	return 0;
}