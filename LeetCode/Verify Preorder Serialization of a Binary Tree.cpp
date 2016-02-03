#include<string>
#include<vector>
//题目描述:给定一个二叉树的先序遍历，null指针用#表示，例如"9,3,4,#,#,1,#,#,2,#,6,#,#",判断是不是正确的先序
//解法描述:先根据,进行split，记录出度与入度的差，非空节点提供2个出度和一个入度，空节点提供1个入度，遍历过程中
//        diff都不能小于0，如果是正确的先序遍历，diff最后一定是0
bool isValidSerialization(std::string preorder) 
{
	std::vector<std::string> vec;
	int i = 0, j = 0;
	for (; j < preorder.size(); ++j)//根据,进行split
	{
		if (preorder[j] == ',')
		{
			vec.push_back(preorder.substr(i, j - i));
			i = j + 1;
		}
	}
	vec.push_back(preorder.substr(i, j - i));

	int diff = 1; //注意这里要初始化为1，因为根节点
	for (i = 0; i < vec.size(); ++i)
	{
		--diff;
		if (diff < 0)
			return false;
		if (vec[i] != "#")
			diff += 2;
	}
	return diff == 0;
}