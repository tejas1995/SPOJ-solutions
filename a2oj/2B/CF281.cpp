#include <iostream>
using namespace std;

int main()
{
	int x, y, a, b, n;
	cin >> x >> y >> n;
	float frac = (float)x/y, frac2;
	int minA, minB;
	float minDiff = -1.0, diff;
	for(int b = 1; b <= n; b++){
		a = (int)(frac*b);
		frac2 = (float)a/b;
		diff = (frac > frac2 ? frac-frac2 : frac2-frac);
		if(diff < minDiff || minDiff < 0){
			minDiff = diff;
			minA = a;
			minB = b;
		}
		frac2 = (float)(a+1)/b;
		diff = (frac > frac2 ? frac-frac2 : frac2-frac);
		if(diff < minDiff || minDiff < 0){
			minDiff = diff;
			minA = a+1;
			minB = b;
		}
	}
	int i = 2;
	while(i <= minA && i <= minB){
		if(minA % i == 0 && minB % i == 0){
			minA /= i;
			minB /= i;
		}
		else
			i++;
	}
	cout << minA << "/" << minB << endl;
	return 0;
}