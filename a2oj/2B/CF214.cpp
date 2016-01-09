//http://codeforces.com/problemset/problem/214/B

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int numDigs[10] = {0};
	int x, sum=0;
	for(int i = 0; i < n; i++){
		cin >> x;
		numDigs[x]++;
		sum += x;
	}
	if(numDigs[0] == 0){
		cout << "-1" << endl;
		return 0;
	}
	if(sum%3 != 0){
		int rem = sum%3;
		bool found = false;
		for(int i = 0; i < 10; i++){
			if(numDigs[i] > 0 && (i-rem)%3 == 0){
				numDigs[i]--;
				found = true;
				break;
			}
		}
		if(!found){
			for(int i = 0; i < 10; i++){
				if(numDigs[i] > 1 && (2*i-rem)%3 == 0){
					numDigs[i] -= 2;
					found = true;
					break;
				}
			}
			if(!found){
				for(int i = 1; i < 10; i+=3)
					numDigs[i] = 0;
				for(int i = 2; i < 10; i+=3)
					numDigs[i] = 0;
			}
		}
	}

	bool zero=true;
	for(int i = 1; i < 10; i++)
		if(numDigs[i] != 0){
			zero = false;
			break;
		}
	if(zero && numDigs[0] > 0){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 9; i >= 0; i--){
		for(int j = numDigs[i]; j > 0; j--)
			cout << i;
	}
	cout << endl;
	return 0;
}