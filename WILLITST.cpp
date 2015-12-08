#include <iostream>
using namespace std;

void willItStop(long long int n)
{
    while(n > 1)
    {
        if(n % 2 == 1)
        {
            cout << "NIE" << endl;
            return;
        }
        n /= 2;
    }

    cout << "TAK\n";
    return;
}
int main()
{
    long long int n;
    cin >> n;

    willItStop(n);

    return 0;
}