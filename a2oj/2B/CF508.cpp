//http://codeforces.com/problemset/problem/508/B

#include <iostream>
#include <string.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

int main()
{
    char rate[100005];
    cin.getline(rate, 100005);

    char last_dig = rate[strlen(rate)-1], temp;

    int last_even_index=-1, over=0;
    for(int i = 0; i < strlen(rate); i++)
    {
        if((rate[i])%2 == 0)
            if(rate[i] < last_dig)
            {
                rate[strlen(rate)-1] = rate[i];
                rate[i] = last_dig;
                last_even_index = i;
                over = 1;
                break;
            }
            else
                last_even_index = i;
    }

    if(last_even_index == -1)
        cout << "-1\n";
    else
    {
        if(over == 0)
        {
            rate[strlen(rate)-1] = rate[last_even_index];
            rate[last_even_index] = last_dig;
        }
        int j = 0;
        cout << rate << endl;
    }
}