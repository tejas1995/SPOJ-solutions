//http://codeforces.com/problemset/problem/157/B

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

#define PI 3.14159265358979
int main()
{
    int n;
    cin >> n;
    vector<double> r;
    double k;
    for(int i = 0; i < n; i++){
        cin >> k; r.push_back(k);
    }
    sort(r.begin(), r.end());

    double red = 0.0;
    vector<double>::iterator it;
    for(it=r.end()-1; it>r.begin()+1;it-=2){
        red += PI*((*it)*(*it)-(*(it-1))*(*(it-1)));
    }
    if(it == r.begin())
        red += PI*r[0]*r[0];
    else
        red += PI*(r[1]*r[1]-r[0]*r[0]);

    cout << fixed << setprecision(10) << red << endl;
    return 0;
}