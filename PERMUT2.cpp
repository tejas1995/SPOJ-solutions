#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long t, n;

    while(true)
    {
        cin >> t;

        if(!t)
            break;

        vector<long> vec;
        for(long i = 0; i < t; i++)
        {
            cin >> n;
            vec.push_back(n);
        }

        bool ambiguous = true;
        for(long i = 0; i < t; i++)
        {
            if(vec[i] != (find(vec.begin(), vec.end(), i+1) - vec.begin() )+1)
            {
                ambiguous = false;
                break;
            }
        }
        if(ambiguous)
            cout << "ambiguous\n";
        else
            cout << "not ambiguous\n";
    }
}