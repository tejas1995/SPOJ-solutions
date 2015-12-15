//http://codeforces.com/problemset/problem/279/B

#include <iostream>
using namespace std;

int main()
{
    int maxSegSize = 0, segTime=0, n, t, start=0, end;
    cin >> n >> t;

    int *a = new int [n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        end = i;
        segTime += a[i];
        while(segTime > t && start <= end){
            segTime -= a[start];
            start++;
        }
        if(end-start+1 > maxSegSize)
            maxSegSize = end-start+1;
    }
    cout << maxSegSize << endl;
    return 0;
}