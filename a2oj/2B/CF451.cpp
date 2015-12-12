#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

int main()
{
    int n, k, startPos, endPos;
    vector<int> givenArr, sortedArr;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        givenArr.push_back(k);
        sortedArr.push_back(k);
    }
    sort(sortedArr.begin(), sortedArr.end());

    vector<int>::iterator fwdIt = givenArr.begin(), backIt = givenArr.end()-1, soIt = sortedArr.begin();
    while(*fwdIt == *soIt && fwdIt != givenArr.end() && soIt != sortedArr.end())
    {
        fwdIt++;
        soIt++;
    }
    startPos = (fwdIt - givenArr.begin()) + 1;

    soIt = sortedArr.end()-1;
    while(*backIt == *soIt && backIt != givenArr.begin() && soIt != sortedArr.begin())
    {
        backIt--;
        soIt--;
    }
    endPos = (backIt - givenArr.begin()) + 1;

    if(endPos < startPos)
    {
        cout << "yes\n1 1\n";
        return 0;
    }

    int temp;
    while(fwdIt <= backIt)
    {
        temp = *fwdIt;
        *fwdIt = *backIt;
        *backIt = temp;
        fwdIt++;
        backIt--;
    }

    if(givenArr == sortedArr)
    {
        cout << "yes" << endl;
        cout << startPos << " " << endPos << endl;
    }
    else
        cout << "no" << endl;
}