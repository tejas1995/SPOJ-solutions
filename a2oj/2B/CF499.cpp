//http://codeforces.com/problemset/problem/499/B

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> translation;

int main()
{
    int n, m;
    string l1, l2;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> l1 >> l2;
        translation[l1] = l2;
    }

    string *profNotes = new string [n];

    for(int i = 0; i < n; i++)
        cin >> profNotes[i];

    for(int i = 0; i < n; i++)
        if((profNotes[i]).length() <= (translation[profNotes[i]]).length())
            cout << profNotes[i] << " ";
        else
            cout << translation[profNotes[i]] << " ";
    cout << endl;
}