#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        
        unsigned long long int n, numUpTris = 0, numDownTris = 0;
        cin >> n;

        numUpTris = n*(n+1)*(n+2)/6;

        if(n % 2 == 0)
            numDownTris = n*(n+1)*(n+2)/12 - n*(n+2)/8;
        else
            numDownTris = n*(n+1)*(n+2)/12 - (n+1)*(n+1)/8;

        cout << numUpTris + numDownTris << endl;
    }
}