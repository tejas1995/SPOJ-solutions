//Problem statement: http://codeforces.com/problemset/problem/266/B

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, t;
    char order[51];
    cin >> n >> t;
    
    cin.ignore();
    cin.getline(order, 51);

    while(t--)
    {
        int i = 0;
        while(i < n-1)
        {
            
            if(order[i] == 'B' && order[i+1] == 'G')
            {
                order[i] = 'G';
                order[i+1] = 'B';
                i += 2;
            }
            else
                i++;
            
        }
    }
    for(int i = 0; i < n; i++)
        cout << order[i];
    cout << endl;
}