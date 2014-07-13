#include<iostream>
#include<string>
#include<cctype>


bool isPalindrome(std::string s)
{
	int first = 0, last = s.length() - 1;
	while (first <= last)
	{
		if (!isalnum(s[first]))
		{
			++first;
		}
		else if (!isalnum(s[last]))
		{
			--last;
		}
		else
		{
			if (tolower(s[first]) != tolower(s[last]))//ignore case
				return false;
			else
			{
				++first;
				--last;
			}
		}
	}
	return true;
}