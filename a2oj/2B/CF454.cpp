//http://codeforces.com/problemset/problem/454/B

#include <iostream>
using namespace std;

int main()
{
    int n, i;
    int *seq;
    cin >> n;

    seq = new int [n];
    for(i = 0; i < n; i++)
        cin >> seq[i];

    bool found_unsorted = false;
    int unsorted_index;
    for(i = 0; i < n; i++)
        if(seq[i%n] > seq[(i+1)%n])
        {
            if(found_unsorted == false){
                found_unsorted = true;
                unsorted_index = i;
            }
            else
            {
                cout << "-1\n";
                return 0;
            }
        }

    if(found_unsorted == false)
        cout << "0\n";
    else
        cout << n-(unsorted_index+1) << endl;

    return 0;
}