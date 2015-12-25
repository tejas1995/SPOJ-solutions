//http://codeforces.com/problemset/problem/437/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortVec(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}

int main()
{
    int s, l;
    cin >> s >> l;
    vector<int> *lowbit = new vector<int> [l+1];
    for(int i = 1; i <= l; i++)
    {
        if(i%2 == 1){
            lowbit[i].push_back(i);
            lowbit[i].push_back(1);
        }
        else{
            lowbit[i].push_back(i);
            lowbit[i].push_back(2*lowbit[i/2][1]);
        }
    }
    lowbit[0].push_back(0);
    lowbit[0].push_back(0);
    sort(lowbit, lowbit+l+1, sortVec);

    int remaining = s;
    vector<vector<int> > S;
    for(int p = l; p > 0; p--){
        if(lowbit[p][1] <= remaining){
            remaining -= lowbit[p][1];
            S.push_back(lowbit[p]);
        }
    }

    if(remaining > 0){
        cout << "-1\n"; return 0;
    }
    cout << S.size() << endl;
    for(int i = 0; i < S.size(); i++)
        cout << S[i][0] << " ";
    cout << endl;
}