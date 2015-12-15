//http://codeforces.com/problemset/problem/362/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> dirty;
    int n, m, k;
    cin >> n >> m;
    if(m == 0)
    {
        cout << "YES\n";
        return 0;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> k;
        dirty.push_back(k);
    }
    sort(dirty.begin(), dirty.end());

    if(dirty[0] == 1 || dirty[dirty.size()-1] == n)
    {
        cout << "NO\n";
        return 0;
    }

    bool cont = false;
    int segLen = 0;
    for(vector<int>::iterator it=dirty.begin(); it!=dirty.end()-1; it++)
    {
        if(*it == *(it+1)-1)
        {
            if(cont)
                segLen++;
            else
            {
                cont = true;
                segLen = 2;
            }

            if(segLen == 3)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        else if(cont)
            cont = false;
    }
    cout << "YES\n";
    return 0;
}