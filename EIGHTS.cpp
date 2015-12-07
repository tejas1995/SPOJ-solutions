#include <iostream>
using namespace std;

typedef unsigned long long int uLong;

int main()
{
    uLong N, K, t;
    cin >> t;

    while(t--)
    {
        cin >> K;
        cout << 192 + (K-1)*250 << endl;
    }
}