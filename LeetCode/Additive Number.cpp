#include<string>
#include<vector>

bool isAdditiveNumber(std::string num) 
{
	if (num.size() < 3)
		return false;

	std::vector<bool> dp(num.size(), false);
	for (int i = 0; i < num.size() - 2; ++i)
	{
		for (int j = i + 1; j < num.size() - 1; ++j)
		{
			int num1 = stoi(num.substr(0, i + 1));
			int num2 = stoi(num.substr(i + 1, j - i));
			for (int k = j + 1; k < num.size(); ++k)
			{
				int num3 = stoi(num.substr(j + 1, k - j));

			}
		}
	}
}