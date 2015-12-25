//http://codeforces.com/problemset/problem/431/C

#include <iostream>
using namespace std;

//Dp[n][0] = Dp[n-1][0] + ... + Dp[n-min(d-1,n)][0]
//Dp[n][1] = Dp[n-1][1] + ... + Dp[n-min(d-1,n)][1] + (Dp[n-d][0] + Dp[n-d][1]) + ... + (Dp[n-min(n,k)][0] + Dp[n-min(n,k)][1])
int min(int a, int b)
{
    return (a < b ? a : b);
}

int main()
{
    int n, k, d;
    cin >> n >> k >> d;

    long long int **dp = new long long int * [n+1];
    for(int i = 0; i <= n; i++)
        dp[i] = new long long int [2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
        for(int j = 1; j <= min(d-1, i); j++){
            dp[i][0] = (dp[i][0]+dp[i-j][0])%1000000007;
            dp[i][1] = (dp[i][1]+dp[i-j][1])%1000000007;
        }
        for(int j = d; j <= min(i, k); j++)
            dp[i][1] = (dp[i][1]+dp[i-j][0]+dp[i-j][1])%1000000007;
    }

    cout << dp[n][1] << endl;
    return 0;
}