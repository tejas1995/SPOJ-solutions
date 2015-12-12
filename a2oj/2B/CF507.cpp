//http://codeforces.com/problemset/problem/507/B

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x1, x2, y1, y2, r;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    double distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    int minSteps = int(distance/(2*r));
    if(distance/(2*r) > minSteps)
        cout << minSteps+1 << endl;
    else
        cout << minSteps << endl;
}