#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long int uLong;

int stringToNum(string str)
{
    int num = 0;
    for(int i = 0; i < str.length(); i++)
    {
        num *= 10;
        num += (str[i] - 48);
    }
    return num;
}

int main()
{
    uLong t;
    cin >> t;
    cin.ignore();

    while(t--)
    {
        string sum_str, blank_str;
        do
        {
            getline(cin, sum_str);
        } while(sum_str == "");

        int addend1, addend2, sum;
        int plus_pos = sum_str.find("+");
        int is_pos = sum_str.find("=");
        int machula_pos = sum_str.find("machula");

        if(machula_pos < plus_pos)
        {
            addend2 = stringToNum(sum_str.substr(plus_pos+2, is_pos-plus_pos-3));
            sum = stringToNum(sum_str.substr(is_pos+2));
            addend1 = sum - addend2;
        }
        else if(machula_pos > is_pos)
        {
            addend1 = stringToNum(sum_str.substr(0, plus_pos-1));
            addend2 = stringToNum(sum_str.substr(plus_pos+2, is_pos-plus_pos-3));
            sum = addend1 + addend2;
        }
        else
        {
            addend1 = stringToNum(sum_str.substr(0, plus_pos-1));
            sum = stringToNum(sum_str.substr(is_pos+2));
            addend2 = sum - addend1;
        }

        cout << addend1 << " + " << addend2 << " = " << sum << endl;
    }
}