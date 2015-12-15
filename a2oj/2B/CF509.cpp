//http://codeforces.com/problemset/problem/509/B

#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int [n];
    int min = 101, max = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    if(max-min > k){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < min; j++)
            cout << "1 ";
        for(int k = 1; min+k <= a[i]; k++)
            cout << k << " ";
        cout << endl;
    }
    return 0;
}