//http://codeforces.com/problemset/problem/467/B

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int *army;
    int n, m, k;
    cin >> n >> m >> k;

    army = new int [m+1];
    for(int i = 0; i < m+1; i++)
        cin >> army[i];

    int numFriends = 0;
    for(int i = 0; i < m; i++)
    {
        int diff = 0;
        for(int j = 1; j <= n; j++)
        { 
            if((army[i]%int(pow(2, j)))/int(pow(2, j-1)) != (army[m]%int(pow(2, j)))/int(pow(2, j-1)))
                diff++;
        }
        if(diff <= k)
            numFriends++;
    }
    cout << numFriends << endl;
}