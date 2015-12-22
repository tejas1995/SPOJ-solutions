//http://codeforces.com/problemset/problem/401/C

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int num0 = n, num1 = m;
    if(num1 > 2*(num0+1) || num0 > num1+1){
        cout << "-1\n"; return 0;
    }

    while(num1 > num0){
        cout << "11";
        num1 -= 2;
        if(num0 == num1 || num0 == num1+1)
            break;
        else{
            cout << "0"; num0--;
        }
    }
    while(num0 > 0)
    {
        cout << "0"; num0--;
        if(num1 > 0){
            cout << "1"; num1--;
        }
    }
    cout << endl;
    return 0;
}