//http://codeforces.com/problemset/problem/365/B

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int best=0, total=0, previousA=0, previousB=0, current=0;
	for(int k = 0; k < n; k++){

        previousB = previousA;
        previousA = current;
        cin >> current;
        if(current == previousA + previousB || total <= 1){++total; if(total > best){best = total;}}
        else{total = 2;}

    }
    cout << best << endl;
}