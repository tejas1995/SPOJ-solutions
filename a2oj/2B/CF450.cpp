//http://codeforces.com/problemset/problem/450/B

#include <iostream>
using namespace std;

int main()
{
    long long int x, y, n;
    long long int f[6];
    cin >> x >> y >> n;

    f[0] = x;
    f[1] = y;
    for(int i = 2; i < 6; i++)
    {
        f[i] = f[i-1] - f[i-2];
    }
    long long int ans = f[(n-1)%6] % 1000000007;
    if(ans < 0)
        cout << 1000000007 + ans << endl;
    else
        cout << ans << endl;
    return 0;
}