//http://codeforces.com/problemset/problem/231/B

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, d, l;
	cin >> n >> d >> l;
	int min = (n-n/2)*1 - (n/2)*l;
	int max = (n-n/2)*l - (n/2)*1;
	if(d > max || d < min){
		cout << "-1\n";
		return 0;
	}
	int *a = new int [n];
	for(int i = 0; i < n; i+=2)
		a[i] = l;
	for(int i = 1; i < n; i+=2)
		a[i] = 1;
	int diff = max;
	int currIndex = 0;
	while(diff != d){
		if(currIndex%2 == 0){
			a[currIndex]--;
			diff--;
			if(a[currIndex] == 1)
				currIndex += 2;
			if(currIndex >= n)
				currIndex = 1;
		}
		else{
			a[currIndex]++;
			diff--;
			if(a[currIndex] == l)
				currIndex += 2;	
		}
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}