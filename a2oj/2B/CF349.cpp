//http://codeforces.com/problemset/problem/349/B

#include <iostream>
using namespace std;

int main()
{
	int a[10], v;
	cin >> v;
	for(int i = 1; i < 10; i++)
		cin >> a[i];
	int minD = -1, minDigit;
	for(int i = 1; i < 10; i++){
		if(a[i] <= minD || minD < 0){
			minD = a[i];
			minDigit = i;
		}
	}
	if(v < minD){
		cout << "-1\n"; return 0;
	}

	int occ[10] = {0};
	occ[minDigit] = v/minD;
	int remPaint = v%minD, remDigit = 9;
	while(remPaint > 0 && remDigit > minDigit)
	{
		int currDiff = a[remDigit] - a[minDigit];
		occ[minDigit] -= remPaint/currDiff;
		occ[remDigit] += remPaint/currDiff;
		remPaint %= currDiff;
		remDigit--;
	}

	for(int i = 9; i >= 1; i--){
		for(int j = 0; j < occ[i]; j++)
			cout << i;
	}
	cout << endl;
	return 0;
}