#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

typedef unsigned long long int uLong;
map<uLong, uLong> maxDollars;

uLong getMaxDollars(uLong n)
{
    map<uLong, uLong>::iterator maxDollarsIter = maxDollars.find(n);

    if(maxDollarsIter != maxDollars.end())
        return (*maxDollarsIter).second;
    else
    {
        uLong exchangeVal = getMaxDollars(n/2) + getMaxDollars(n/3) + getMaxDollars(n/4);
        
        if(exchangeVal > n)
            maxDollars[n] = exchangeVal;
        else
            maxDollars[n] = n;

        return maxDollars[n];
    }
    
}

int main()
{
    long long int N;
    int t = 10;

    maxDollars[0] = 0;
    maxDollars[1] = 1;

    while(scanf("%lld",&N)!=EOF && t--)
    {
        cout << getMaxDollars(N) << endl;
    }
}