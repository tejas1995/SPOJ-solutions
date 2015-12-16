//http://codeforces.com/problemset/problem/387/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool greaterThan(int a, int b)
{
    if(a>b)
        return true;
    else
        return false;
}

int main()
{
    int n, m, k;
    vector<int> a,b;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> k;
        a.push_back(k);
    }
    for(int i = 0; i < m; i++){
        cin >> k;
        b.push_back(k);
    }

    vector<int>::iterator aIt, bIt;
    int newProbs = 0;
    for(aIt = a.begin(); aIt != a.end(); aIt++)
    {
        bIt = b.begin();
        while(*bIt < *aIt && bIt != b.end())
            bIt++;

        if(bIt == b.end()){
            newProbs++;
        }
        else
            b.erase(bIt);
    }
    cout << newProbs << endl;
    return 0;
    
}