//http://codeforces.com/problemset/problem/448/B

#include <iostream>
#include <string>
#include <map>
using namespace std;

bool find_in_order(string s1, string s2)
{
    int i=0, j=0;
    for(; i < s1.length() && j < s2.length(); i++)
    {
        if(s1[i] == s2[j])
            j++;
    }
    if(i == s1.length() && j < s2.length())
        return false;
    else
        return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    map<char, int> s1_map, s2_map;
    for(int i = 0; i < s1.length(); i++)
        if(s1_map.find(s1[i]) == s1_map.end())
            s1_map[s1[i]] = 1;
        else
            s1_map[s1[i]] += 1;

    for(int i = 0; i < s2.length(); i++)
        if(s2_map.find(s2[i]) == s2_map.end())
            s2_map[s2[i]] = 1;
        else
            s2_map[s2[i]] += 1;

    map<char, int>::iterator it;
    for(it = s2_map.begin(); it != s2_map.end(); it++)
    {
        char k = it->first;
        if(s1_map[k] < s2_map[k])
        {
            cout << "need tree\n";
            return 0;
        }
    }

    bool s2_in_order = find_in_order(s1, s2);

    if(s1.length() > s2.length())
    {
        if(s2_in_order)
            cout << "automaton\n";
        else
            cout << "both\n";
    }
    else
        cout << "array\n";

    return 0;
}