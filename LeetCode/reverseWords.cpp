#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

void reverseWords(string& s)
{
	string temp("");
	vector<string> result;
	string::iterator iter = s.begin();
	while (iter != s.end())
	{
		if (isspace(*iter) && temp != "")
		{
			result.push_back(temp);
			temp = "";
		}

		if (!isspace(*iter))
			temp += *iter;

		++iter;
	}

	if (temp != "")
		result.push_back(temp);

	reverse(result.begin(), result.end());

	s = "";
	vector<string>::iterator first = result.begin();
	while (first != result.end())
	{
		s += *first;
		++first;
		if (first != result.end())
			s += " ";
	}
}

