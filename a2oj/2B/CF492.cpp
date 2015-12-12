//http://codeforces.com/problemset/problem/492/B

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, l, k;
    cin >> n >> l;
    vector<double> lampPos;

    for(int i = 0; i < n; i++)
    {
        cin >> k;
        lampPos.push_back(double(k));
    }
    sort(lampPos.begin(), lampPos.end());

    double lampRad = lampPos[0];

    for(vector<double>::iterator it = lampPos.begin()+1; it != lampPos.end(); it++)
        if((*it - *(it-1))/2 > lampRad)
            lampRad = (*it - *(it-1))/2;
    if(l - lampPos[n-1] > lampRad)
        lampRad = l - lampPos[n-1];
    cout << fixed << setprecision(10) << lampRad << endl;
}