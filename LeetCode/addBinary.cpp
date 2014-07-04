#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string addBinary(string a, string b)
{
	string result(max(a.length(), b.length()) + 1, ' ');

	int index = result.length() - 1;
	int indexA = a.length() - 1, indexB = b.length() - 1;
	bool add = false;
	while (index > 0)
	{
		char A = ' ', B = ' ';
		if (indexA < 0)
			A = '0';
		else
			A = a[indexA];
		if (indexB < 0)
			B = '0';
		else
			B = b[indexB];

		if (add == true)
		{
			if (A == '1' && B == '1')
			{
				result[index] = '1';
			}
			else if (A == '1' || B == '1')
			{
				result[index] = '0';
			}
			else
			{
				result[index] = '1';
				add = false;
			}
		}
		else
		{
			if (A == '1' && B == '1')
			{
				result[index] = '0';
				add = true;
			}
			else if (A == '1' || B == '1')
			{
				result[index] = '1';
			}
			else
			{
				result[index] = '0';
			}
		}
		--index;
		--indexB;
		--indexA;
	}
	if (add == true)
		result[0] = '1';
	else
		result = result.substr(1);
	return result;
}