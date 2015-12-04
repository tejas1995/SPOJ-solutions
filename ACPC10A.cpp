#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3;

	while(true)
	{
		cin >> num1 >> num2 >> num3;

		if(num1 == 0 && num2 == 0 && num3 == 0)
			break;
		else
		{
			if(num2-num1 == num3-num2)
			{
				cout << "AP ";
				cout << num3+num2-num1 << endl;
			}
			else
			{
				cout << "GP " << num3 * num2 / num1 << endl;
			}
		}
	}

	return 0;
}