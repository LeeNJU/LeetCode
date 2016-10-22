#include<string>
#include<vector>
//题目描述:给定一个字符串，由数字0到9的英文单词组成，但是字符之间的顺序被打乱，要求返回对应的数字字符串，例如
//        给定字符串"owoztneoer"，该字符串表示"zereoonetwo",那么就返回"012"
//解法描述:每个数字的英文单词都有独特的字符，例如只有zero包含z，只有two包含w，用一个数组表示每个数字出现的
//        次数

std::string originalDigits(std::string s) 
{
	std::vector<int> count(10, 0);
	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];
		if (c == 'z') 
			++count[0];
		if (c == 'w') 
			++count[2];
		if (c == 'x') 
			++count[6];
		if (c == 's')//注意这里，6和7都包含s 
			++count[7]; //7-6
		if (c == 'g') 
			++count[8];
		if (c == 'u') 
			++count[4];
		if (c == 'f') 
			++count[5]; //5-4
		if (c == 'h') 
			++count[3]; //3-8
		if (c == 'i') 
			++count[9]; //9-8-5-6
		if (c == 'o') 
			++count[1]; //1-0-2-4
	}

	count[7] -= count[6];//减去6出现的次数得到7出现的次数
	count[5] -= count[4];
	count[3] -= count[8];
	count[9] = count[9] - count[8] - count[5] - count[6];
	count[1] = count[1] - count[0] - count[2] - count[4];
	
	std::string result = "";
	for (int i = 0; i <= 9; i++)//统计每个字符出现的次数
	{
		for (int j = 0; j < count[i]; j++)
			result += std::to_string(i);
	}
	return result;
}