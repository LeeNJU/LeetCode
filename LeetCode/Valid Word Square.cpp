#include<vector>
#include<string>
//题目描述:给定一个字符串数组，判断其是不是valid square,第i行和第i列必须相等，例如
//       [
//        "abcd",
//        "bnrt",
//        "crmy",
//        "dtye"
//       ]
//解法描述:该二维数组必须是对称的，从第i行开始，扫描第i行，确保words[i][j] == words[j][i],要注意下标的范围，
//        保持下标是合法的

bool validWordSquare(std::vector<std::string>& words) 
{
	for (int i = 0; i < words.size(); ++i) 
	{
		for (int j = 0; j < words[i].size(); ++j)             {
			if (j >= words.size() || words[j].size() <= i || words[j][i] != words[i][j])
				return false;
		}
	}
	return true;
}