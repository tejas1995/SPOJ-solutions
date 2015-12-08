#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef unsigned long long int uLong;

map<string, uLong> numDecodings;

uLong findNumDecodings(string code, int pos)
{
    string part_str = code.substr(pos);
    
    if(part_str.size() == 0)
    {
        return 1;
    }
    else if(part_str.size() == 1)
    {
        if(part_str[0] > 48)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(numDecodings.find(part_str) != numDecodings.end())
            return (*(numDecodings.find(part_str))).second;
        else
        {
            uLong num = 0;
            if(part_str[0] > 48)
            {
                num += findNumDecodings(part_str, 1);
                if(10*(part_str[0]-48) + part_str[1]-48 <= 26)
                {
                    num += findNumDecodings(part_str, 2);
                }
            }

            numDecodings[part_str] = num;
            return num;
        }
    }
}

int main()
{
    string code;

    while(true)
    {
        cin >> code;
        if(code == "0")
            break;
        else
            cout << findNumDecodings(code, 0) << endl; 
    }
    return 0;
}