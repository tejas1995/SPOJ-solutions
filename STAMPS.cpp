#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool greaterThan(long a, long b)
{
    return (a > b);
}

void findMinFriends(vector<long> vec, long raymondStamps)
{
    vector<long>::iterator it;
    long sum = 0;

    for(it = vec.begin(); it != vec.end(); it++)
    {
        sum += (*it);
        if(sum >= raymondStamps)
        {
            cout << (it - vec.begin()) + 1 << endl << endl;
            return;
        }
    }

    cout << "impossible" << endl << endl;
    return;
}

int main()
{
    long long int t;
    cin >> t;

    for(long long int j = 1; j <= t; j++)
    {
        long int raymondStamps;
        int numFriends, n;
        vector<long> vecStamps;

        cin >> raymondStamps >> numFriends;
        for(int i = 0; i < numFriends; i++)
        {
            cin >> n;
            vecStamps.push_back(n);
        }
        sort(vecStamps.begin(), vecStamps.end(), greaterThan);

        cout << "Scenario #" << j << ":" << endl;
        findMinFriends(vecStamps, raymondStamps);
    }
}