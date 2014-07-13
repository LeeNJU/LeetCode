#include<iostream>
#include<map>

using namespace std;


int singleNumber(int A[], int n)
{
	map<int, int> m;

	for (int i = 0; i < n; ++i)
	{
		++m[A[i]];
	}

	map<int, int>::iterator iter = m.begin();
	while (iter != m.end())
	{
		if (iter->second == 1)
			return iter->first;
		++iter;
	}
	return 0;
}
