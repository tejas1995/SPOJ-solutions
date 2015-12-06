#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class bigInteger
{
    char num_str[101];
    
    vector<int>::iterator valIter;

public:
    vector<int> val;

    bigInteger(char *str=NULL)
    {
        if(str != NULL)
        {
            strcpy(num_str, str);
            int len = strlen(num_str);
            for(int i = len-1; i >= 0; i--)
                val.push_back(num_str[i]-48);
        }
    }

    char *print()
    {
        for(vector<int>::iterator iter = val.end()-1; iter >= val.begin(); iter--)
            cout << (*iter);
        cout << endl;
    }

    bigInteger operator+(bigInteger b);
    bigInteger operator-(bigInteger b);
    void divideByTwo();
};

bigInteger bigInteger::operator+(bigInteger b)
{
    bigInteger temp;
    int carry = 0, next_dig;

    vector<int>::iterator iter1 = this->val.begin(), iter2 = b.val.begin();
    while(iter1 != this->val.end() || iter2 != b.val.end())
    {
        if(iter1 == this->val.end())
        {
            next_dig = carry + (*iter2);
            iter2++;
        }
        else if (iter2 == b.val.end())
        {
            next_dig = carry + (*iter1);
            iter1++;
        }
        else
        {
            next_dig = (*iter1) + (*iter2) + carry;
            iter1++;
            iter2++;
        }

        carry = next_dig / 10;
        next_dig %= 10;
        temp.val.push_back(next_dig);
    }
    if(carry != 0)
        temp.val.push_back(carry);
    return temp;
}

bigInteger bigInteger::operator-(bigInteger b)
{
    bigInteger temp;
    int borrow = 0, next_dig;
    vector<int>::iterator iter1 = this->val.begin(), iter2 = b.val.begin();

    while(iter1 != this->val.end())
    {
        if(iter2 == b.val.end())
        {
            next_dig = (*iter1) - borrow;
            iter1++;
        }
        else
        {
            next_dig = (*iter1) - (*iter2) - borrow;
            iter1++;
            iter2++;
        }
        
        if(next_dig < 0)
        {
            next_dig += 10;
            borrow = 1;
        }
        else
            borrow = 0;   
        temp.val.push_back(next_dig);
    }
    return temp;
}

void bigInteger::divideByTwo()
{
    vector<int>::iterator iter = this->val.end()-1;
    int rem = 0, result;
    while(iter >= this->val.begin())
    {
        result = (rem*10 + (*iter))/2;
        rem = (rem*10 + (*iter))%2;
        *iter = result;
        iter--;
    }

    while(this->val[ this->val.size()-1 ] == 0 && this->val.size() > 1)
        this->val.pop_back();
}

int main()
{
    char total_str[102], diff_str[102];
    
    for(int i = 0; i < 10; i++)
    {
        cin.getline(total_str, 102);
        cin.getline(diff_str, 102);

        bigInteger total(total_str);
        bigInteger diff(diff_str);
    
        bigInteger klaudia = total + diff;
        klaudia.divideByTwo();

        bigInteger natalia = total - diff;
        natalia.divideByTwo();

        klaudia.print();
        natalia.print();
    }

    return 0;
}