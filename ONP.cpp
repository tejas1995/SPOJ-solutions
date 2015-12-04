#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
	int t;
	cin >> t;
	cin.ignore();

	char str[400];
	stack <char> s;

	while(t--)
	{
		cin.getline(str, 400);
        int len = strlen (str);

        for(int i=0;i<len;i++ ) 
        {
            if(isalpha(str[i]))
                cout << str[i];
            else if(str[i] == ')' ) 
            {
                cout << s.top ();
                s.pop ();
            }

            else if (str[i] != '(' )
                s.push (str[i]);
        }

        cout << endl;

	}
}