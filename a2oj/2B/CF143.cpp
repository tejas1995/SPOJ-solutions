//http://codeforces.com/problemset/problem/143/B
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool neg = 0;
    if(s[0] == '-')
        neg = 1;
    int decPos = 0;
    while(s[decPos] != '.' && decPos < s.length())
        decPos++;
    if(neg)
        cout << "(";
    cout << "$";
    for(int i = neg; i < decPos; i++){
        cout << s[i];
        if((decPos-(i+1))%3 == 0 && i != decPos-1)
            cout << ",";
    }
    cout << ".";
    if(decPos+1 < s.length())
        cout << s[decPos+1];
    else
        cout << "0";
    if(decPos+2 < s.length())
        cout << s[decPos+2];
    else
        cout << "0";
    if(neg)
        cout << ")";
    cout << endl;
    return 0;
}