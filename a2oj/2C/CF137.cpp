#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct period{
	int a, b;
};

bool sortV(period v1, period v2){
	if(v1.a < v2.a)
		return true;
	return false;
}

int main()
{
	int n, a, b, maxRange=0;
	cin >> n;
	period *p = new period [n];

	for(int i = 0; i < n; i++){
		cin >> p[i].a >> p[i].b;
	}
	sort(p, p+n, sortV);
	int numContained = 0;
	int maxB = p[0].b;

	for(int i = 1; i < n; i++)
		if(p[i].b < maxB)
			numContained++;
		else
			maxB = p[i].b;
	cout << numContained << endl;
	return 0;
}