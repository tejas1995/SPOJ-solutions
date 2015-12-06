#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, a;
    unsigned long int b;

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        if(b == 0)
            cout << 1 << endl;
        else
        {
            int baseL = a % 10, nextL = baseL;
            vector<int> lastDig;
            do
            {
                lastDig.push_back(nextL);
                nextL=(nextL*baseL)%10;
            }while(nextL!=baseL);

            if(b % lastDig.size() == 0)
                cout << lastDig[lastDig.size()-1] << endl;
            else
                cout << lastDig[b % lastDig.size()-1] << endl;
        }
    }

    return 0;
}