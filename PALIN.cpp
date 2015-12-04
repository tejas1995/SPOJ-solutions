#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef unsigned long int ulong;

void string_to_array(char str[], int num[], ulong length)
{
	for(ulong i = 0; i < length; i++)
	{
		num[i] = int(str[i]) - 48;
	}
}

void array_to_string(char str[], int num[], ulong length)
{
	for(ulong i = 0; i < length; i++)
		str[i] = char(num[i]+48);
	str[length] = '\0';
}

void string_reverse(char str1[], char str2[], ulong length)
{
	for(ulong i = 0; i < length; i++)
		str2[i] = str1[length-1-i];
	str2[length] = '\0';
}

ulong increment(int num[], ulong length)
{
	int carry = 1;
	ulong curr_digit_index = length-1;

	while(carry && curr_digit_index >= 0)
	{
		num[curr_digit_index] += carry;

		carry = num[curr_digit_index]/10;
		num[curr_digit_index] = num[curr_digit_index] % 10;
		curr_digit_index--;
	}

	if(carry == 1)
	{
		for(ulong i = curr_digit_index; i >= 0; i++)
			num[i+1] = num[i];
		num[0] = 1;

		return length+1;
	}
	else
		return length;
}

void print(int num[], int length)
{
	for(ulong i = 0; i < length; i++)
		cout << num[i];
	cout << endl;
}
int main()
{
	ulong t;
	cin >> t;

	char **K = new char *[t];
	for(ulong i = 0; i < t; i++)
		K[i] = new char [1000000];

	cin.ignore();
	for(ulong i = 0; i < t; i++)
	{
		cin.getline(K[i], 1000000);
	}

	/*
	int *num = new int [1000000];
	string_to_array(K[0], num, strlen(K[0]));
	increment(num, strlen(K[0]));
	print(num, strlen(K[0]));
	*/

	
	for(ulong i = 0; i < t; i++)
	{
		ulong length = strlen(K[i]);
		int *num = new int [1000000];

		string_to_array(K[i], num, length);
		increment(num, length);

		do
		{
			char *num_str = new char [1000000];
			char *num_str_rev = new char [1000000];

			array_to_string(num_str, num, length);
			string_reverse(num_str, num_str_rev, length);

			if(!strcmp(num_str, num_str_rev))
			{
				cout << num_str;
				num_str = NULL;
				num_str_rev = NULL;
				break;
			}

			length = increment(num, length);
			num_str = NULL;
			num_str_rev = NULL;
			
		} while (true);
		

		if(i != t-1)
			cout << endl;

		num = NULL;	
	}
	

	return 0;
}