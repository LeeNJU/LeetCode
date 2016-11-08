#include "TreeNode.h"
#include<string>
#include<sstream>
//题目描述:给定一个二叉树，将其序列化成字符串，然后由字符串反序列化成二叉树
//解法描述:用先序遍历的方法进行序列化，#代替nullptr,用空格作为每个节点之间的分隔符。反序列化的时候，利用
//        istringstream来读取每个节点的值，istringstream会一直读取直到遇到空格或者换行符。

class Codec 
{
private:
	TreeNode* Deserialize(const std::string& data, int& index)
	{
		if (index >= data.size()) 
			return nullptr;
		if (data[index] == '#')
		{
			index = index + 2;
			return nullptr;
		}

		int flag = 1;//有可能是负数
		if (data[index] == '-')
		{
			flag = -1;
			++index;
		}

		int val = 0;
		while (data[index] != ' ')
		{
			val = val * 10 + data[index] - '0';
			++index;
		}

		TreeNode* node = new TreeNode(val * flag);
		node->left = Deserialize(data, ++index);
		node->right = Deserialize(data, index);
		return node;
	}

public:
	std::string serialize(TreeNode* root) 
	{
		if (root == nullptr)
			return "# ";

		std::string left = serialize(root->left);
		std::string right = serialize(root->right);
		return std::to_string(root->val) + " " + left + right;
	}

	TreeNode* deserialize(std::string data) 
	{
		int index = 0;
		return Deserialize(data, index);
	}
};