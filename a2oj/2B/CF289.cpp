//http://codeforces.com/problemset/problem/289/B

#include <iostream>
#include <algorithm>
using namespace std;

int mod(int a)
{
    if(a < 0)
        return -a;
    else
        return a;
}

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    int *a = new int [m*n];
    for(int i = 0; i < m*n; i++)
        cin >> a[i];
    sort(a, a+m*n);
    for(int i = 1; i < m*n; i++)
        if((a[i]-a[i-1])%d != 0){
                cout << "-1\n";
                return 0;
            }

    int *min = new int [m*n];
    int leastMoves = 0;
    int eqVal = a[0];
    for(int i = 0; i < m*n; i++){
        min[i] = mod((a[i]-eqVal)/d);
        leastMoves += min[i];
    }
    do{
        eqVal += d;
        int sum = 0;
        for(int i = 0; i < m*n; i++){
            if(a[i] == eqVal)
                min[i] = 0;
            else if(a[i] > eqVal)
                min[i]--;
            else
                min[i]++;
            sum += min[i];
        }
        if(sum < leastMoves)
            leastMoves = sum;
    }while(eqVal < a[m*n-1]);
    cout << leastMoves << endl;
    return 0;
}