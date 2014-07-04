#include<iostream>

using namespace std;

int lengthOfLastWord(const char* s)
{
	if (s == nullptr || strlen(s) == 0)
		return 0;

	int left = 0, right = 0, length = strlen(s) - 1;
	while (length >= 0)
	{
		if (s[length] != ' ')
		{
			right = right == 0 ? length : right;
		}
		if (s[length] == ' ' && right != 0)
		{
			left = length + 1;
			break;
		}
		--length;
	}

	if (left == right && s[right] == ' ')
		return 0;
	if (left == right && s[right] != ' ')
		return 1;

	return right - left + 1;
}